/********************************************************************************
*                                                                               *
* ClassLinker.h -- Custom functions compilation                                 *
*                                                                               *
* Made by Lulin Pollux.          MIT License                                    *
*                                                                               *
********************************************************************************/


//중복되지 않는 난수를 생성하는 함수 (0 ~ range-1)
int random(int output[], int amount, int range);

//최대공약수를 계산하는 함수
int greatestCommonFactor(int a, int b, int* result);

//최대 숫자를 찾는 함수
int maxNumber(int data[], int amount);

//거스름돈을 계산하는 함수
void coinChange(int input, int change[]);

//합병 정렬을 수행하는 함수
int mergeSort(int data[], int amount);

//합병 정렬의 부분문제를 해결하는 함수
int mergeSort_merging(int data[], int startIndex, int endIndex);

//버블 정렬을 수행하는 함수
int bubbleSort(int data[], int amount);

//선택 정렬을 수행하는 함수
int selectSort(int data[], int amount);

//삽입 정렬을 수행하는 함수
int insertionSort(int data[], int amount);