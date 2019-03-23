#include <stdio.h>


//최대공약수를 계산하는 함수
int greatestCommonFactor(int a, int b, int *result)
{
	/*
	1. 오류제어 a >= b >= 0
	if (!((a >= b) && (b >= 0)))
		return 1;
	*/

	//2. 오류제어, 자동으로 큰 수의 위치변경
	if ((a < 0) || (b < 0))
		return 1;
	else if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

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
int maxNumber(int data[], int count)
{
	int max = data[0];
	for (int i = 1; i <= (count - 1); i++)
	{
		if (data[i] > max)
			max = data[i];
	}
	
	return max;
}

int main()
{
	int retval;

	//최대공약수를 계산하는 코드
	//---------------------------------------------------------------
	int input1, input2, result;
	printf("2개의 정수 데이터 입력: ");
	scanf_s("%d %d", &input1, &input2);

	retval = greatestCommonFactor(input1, input2, &result);
	if (retval != 0)
	{
		printf("오류 발생! \n");
		return 1;
	}

	printf("결과: %d\n", result);


	//최대 숫자 찾는 코드
	//---------------------------------------------------------------
	printf("최대 숫자 찾기: 25 10 20 35 55 45 60 79 90 3 \n");
	int data[10] = { 25, 10, 20, 35, 55, 45, 60, 79, 90, 3 };

	retval = maxNumber(data, 10);
	printf("결과: %d\n", retval);

	return 0;
}