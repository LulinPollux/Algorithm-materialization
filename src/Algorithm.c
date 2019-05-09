#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ClassLinker.h"


//중복되지 않는 난수를 생성하는 함수 (난수 범위: 0 ~ range-1)
int random(int output[], int amount, int range)
{
	//오류제어: 범위보다 난수 개수가 더 많으면 중단함.
	if (amount > range)
		return 1;

	//불규칙 난수 생성 활성화
	srand((unsigned int)time(NULL));

	//난수를 생성한다.
	for (int i = 0; i < amount; i++)
	{
		output[i] = rand() % range;

		//수가 중복되면 다시 뽑는다.
		for (int k = 0; k < i; k++)
		{
			if (output[i] == output[k])
			{
				i--;
				break;
			}
		}
	}

	return 0;
}

//최대공약수를 계산하는 함수
int greatestCommonFactor(int a, int b, int* result)
{
	//오류제어 a >= b >= 0
	if (!((a >= b) && (b >= 0)))
		return 1;

	while (1)
	{
		if (b == 0)
		{
			*result = a;
			return 0;
		}
		else
		{
			int mod = a % b;
			a = b;
			b = mod;
		}
	}
}

//최대 숫자를 찾는 함수
int maxNumber(int data[], int amount)
{
	int max = data[0];
	for (int i = 1; i <= (amount - 1); i++)
	{
		if (data[i] > max)
			max = data[i];
	}

	return max;
}

//거스름돈을 계산하는 함수
void coinChange(int input, int change[])
{
	//1000원 개수를 구하고 남은 돈을 다음 계산으로 넘긴다.
	change[0] = input / 1000;
	input %= 1000;

	//500원 개수를 구하고 남은 돈을 다음 계산으로 넘긴다.
	change[1] = input / 500;
	input %= 500;

	//100원 개수를 구하고 남은 돈을 다음 계산으로 넘긴다.
	change[2] = input / 100;
	input %= 100;

	//50원 개수를 구하고 남은 돈을 다음 계산으로 넘긴다.
	change[3] = input / 50;
	input %= 50;

	//10원 개수를 구하고 남은 돈을 다음 계산으로 넘긴다.
	change[4] = input / 10;
	input %= 10;

	//남은 원 단위를 결과값 배열에 넘겨준다.
	change[5] = input;
}

//합병 정렬을 수행하는 함수
int mergeSort(int data[], int amount)
{
	int retval;

	//오류제어
	//amount가 짝수가 아니면 중단한다.
	if (amount % 2 != 0)
		return 1;

	for (int i = 0; i < amount; i += 2)
	{
		retval = mergeSort_merging(data, i, i + 1);
		if (retval != 0)
			return 1;
	}

	for (int i = 0; i < amount; i += 4)
	{
		retval = mergeSort_merging(data, i, i + 3);
		if (retval != 0)
			return 1;
	}

	for (int i = 0; i < amount; i += 8)
	{
		retval = mergeSort_merging(data, i, i + 7);
		if (retval != 0)
			return 1;
	}

	return 0;
}

//합병 정렬의 부분문제를 해결하는 함수
int mergeSort_merging(int data[], int startIndex, int endIndex)
{
	//필요한 변수를 선언한다.
	int result[100] = { 0 };	//결과값을 저장하는 배열
	int index = 0;			//결과 배열의 인덱스를 저장
	int i, k;			//입력 배열에 사용하는 인덱스
	int half = (startIndex + endIndex) / 2;	//인덱스의 중간값을 저장

	for (i = startIndex, k = half + 1; (i <= half) && (k <= endIndex); index++)
	{
		//1번 배열의 수가 2번 배열의 수보다 작으면 결과배열에 넣고 i++
		//2번 배열의 수가 1번 배열의 수보다 작으면 결과배열에 넣고 k++
		if (data[i] < data[k])
		{
			result[index] = data[i];
			i++;
		}
		else if (data[k] < data[i])
		{
			result[index] = data[k];
			k++;
		}
		else
		{
			//두 수가 같다는 것이므로 오류이다.
			return 1;
		}
	}

	//마지막 1개는 비교가 불가능하므로 그 수는 따로 결과 배열에 넣어준다.
	if (i == half)
		result[index] = data[i];
	else
		result[index] = data[k];

	//입력 배열에 결과값을 복사한다.
	for (i = startIndex, k = 0; i <= endIndex; i++, k++)
	{
		data[i] = result[k];
	}

	return 0;
}

//버블 정렬을 수행하는 함수
int bubbleSort(int data[], int amount)
{
	for (int pass = 1; pass <= amount - 1; pass++)
	{
		for (int i = 1; i <= amount - pass; i++)
		{
			//i - 1번 원소의 수가 i번 원소의 수보다 크면 서로 교환한다.
			if (data[i - 1] > data[i])
			{
				int temp = data[i - 1];
				data[i - 1] = data[i];
				data[i] = temp;
			}
		}
	}

	return 0;
}

//선택 정렬을 수행하는 함수
int selectSort(int data[], int amount)
{
	for (int i = 0; i < amount; i++)
	{
		//필요한 변수를 생성한다.
		int minValue = data[i];	//최솟값을 저장
		int index = i;		//배열에서 최솟값이 있는 위치의 인덱스를 저장

		for (int j = i; j < amount; j++)
		{
			//저정된 최솟값보다 더 작은 수가 있다면 그 수로 덮어쓴다.
			if (data[j] < minValue)
			{
				minValue = data[j];
				index = j;
			}
		}

		//index에 기록된 위치의 최솟값을 앞쪽으로 이동한다.
		int temp = data[i];
		data[i] = data[index];
		data[index] = temp;
	}

	return 0;
}

//삽입 정렬을 수행하는 함수
int insertionSort(int data[], int amount)
{
	for (int i = 1; i <= amount - 1; i++)
	{
		//정렬이 안 된 부분의 가장 왼쪽 원소를 저장한다.
		int currentElement = data[i];
		
		//정렬된 부분의 가장 오른쪽부터 비교하여 큰 수는 오른쪽으로 밀어낸다.
		int k = i - 1;
		while ((k >= 0) && (data[k] > currentElement))
		{
			data[k + 1] = data[k];
			k--;
		}

		//적합한 공간에 값을 저장한다.
		data[k + 1] = currentElement;
	}

	return 0;
}