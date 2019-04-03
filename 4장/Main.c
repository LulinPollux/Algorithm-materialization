#include <stdio.h>


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

int main()
{
	//필요한 변수를 선언한다.
	int input;		//입력값을 저장
	int change[6];	//거스름돈을 저장

	//금액을 입력받는다.
	printf("금액 입력: ");
	scanf_s("%d", &input);
	printf("\n");

	//거스름돈을 계산한다.
	coinChange(input, change);

	//결과를 출력한다.
	printf("1000원: %d개 \n", change[0]);
	printf("500원: %d개 \n", change[1]);
	printf("100원: %d개 \n", change[2]);
	printf("50원: %d개 \n", change[3]);
	printf("10원: %d개 \n", change[4]);
	printf("남은 금액: %d원 \n", change[5]);

	return 0;
}