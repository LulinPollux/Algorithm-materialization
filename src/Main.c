#include <stdio.h>
#include "ClassLinker.h"

int main()
{
	int retval;

	//난수를 생성한다.
	int data[100] = { 0 };
	retval = random(data, 100, 100);
	if (retval != 0)
	{
		printf("오류 발생: %d\n", retval);
		return 1;
	}

	//입력 데이터를 출력한다.
	printf("입력 데이터: ");
	for (int i = 0; i < (sizeof(data) / sizeof(int)); i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n\n");

	//정렬을 한다.
	//정렬 방법 변경: 함수 이름만 바꾸어준다.
	retval = insertionSort(data, 100);
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
}