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

int main()
{
	int retval;

	int input1, input2, result;
	printf("2개의 정수 데이터 입력: ");
	scanf_s("%d %d", &input1, &input2);

	retval = greatestCommonFactor(input1, input2, &result);
	if (retval != 0)
	{
		printf("오류 발생! \n");
		return 1;
	}

	printf("결과: %d", result);
	return 0;
}