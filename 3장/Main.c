#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//난수를 생성하는 함수 (0 ~ range-1)
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
		for (int j = 0; j < i; j++)
		{
			if (output[j] == output[i])
			{
				i--;
				break;
			}
		}
	}

	return 0;
}

//합병 정렬의 부분문제를 해결하는 함수
int mergeSort2(int data[], int startIndex, int endIndex)
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
		retval = mergeSort2(data, i, i + 1);
		if (retval != 0)
			return 1;
	}

	for (int i = 0; i < amount; i += 4)
	{
		retval = mergeSort2(data, i, i + 3);
		if (retval != 0)
			return 1;
	}

	for (int i = 0; i < amount; i += 8)
	{
		retval = mergeSort2(data, i, i + 7);
		if (retval != 0)
			return 1;
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
			if (minValue > data[j])
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

int main()
{
	int retval;

	//난수를 생성한다.
	int data[8] = { 0 };
	retval = random(data, sizeof(data) / sizeof(int), 40);
	if (retval != 0)
	{
		printf("오류 발생: %d\n", retval);
		return 1;
	}

	//데이터를 출력한다.
	printf("데이터: ");
	for (int i = 0; i < (sizeof(data) / sizeof(int)); i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n\n");

	//합병 정렬을 한다.
	retval = mergeSort(data, 8);
	if (retval != 0)
		return 1;

	//결과를 출력한다.
	printf("결과: ");
	for (int i = 0; i < (sizeof(data) / sizeof(int)); i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n\n");
	//----------------------------------------------------------------

	//난수를 생성한다.
	retval = random(data, sizeof(data) / sizeof(int), 100);
	if (retval != 0)
	{
		printf("오류 발생: %d\n", retval);
		return 1;
	}

	//데이터를 출력한다.
	printf("데이터: ");
	for (int i = 0; i < (sizeof(data) / sizeof(int)); i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n\n");

	//선택 정렬을 한다.
	retval = selectSort(data, sizeof(data) / sizeof(int));
	if (retval != 0)
	{
		printf("오류 발생: %d\n", retval);
		return 1;
	}

	//결과를 출력한다.
	printf("결과: ");
	for (int i = 0; i < (sizeof(data) / sizeof(int)); i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n\n");

	return 0;
}