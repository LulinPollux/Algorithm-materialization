#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//�ִ������� ����ϴ� �Լ�
int greatestCommonFactor(int a, int b, int* result)
{
	//�������� a >= b >= 0
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

//�ִ� ���ڸ� ã�� �Լ�
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

//�ߺ����� �ʴ� ������ �����ϴ� �Լ� (0 ~ range-1)
int random(int output[], int amount, int range)
{
	//��������: �������� ���� ������ �� ������ �ߴ���.
	if (amount > range)
		return 1;

	//�ұ�Ģ ���� ���� Ȱ��ȭ
	srand((unsigned int)time(NULL));

	//������ �����Ѵ�.
	for (int i = 0; i < amount; i++)
	{
		output[i] = rand() % range;

		//���� �ߺ��Ǹ� �ٽ� �̴´�.
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

//�պ� ������ �κй����� �ذ��ϴ� �Լ�
int mergeSort2(int data[], int startIndex, int endIndex)
{
	//�ʿ��� ������ �����Ѵ�.
	int result[100] = { 0 };	//������� �����ϴ� �迭
	int index = 0;			//��� �迭�� �ε����� ����
	int i, k;			//�Է� �迭�� ����ϴ� �ε���
	int half = (startIndex + endIndex) / 2;	//�ε����� �߰����� ����

	for (i = startIndex, k = half + 1; (i <= half) && (k <= endIndex); index++)
	{
		//1�� �迭�� ���� 2�� �迭�� ������ ������ ����迭�� �ְ� i++
		//2�� �迭�� ���� 1�� �迭�� ������ ������ ����迭�� �ְ� k++
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
			//�� ���� ���ٴ� ���̹Ƿ� �����̴�.
			return 1;
		}
	}

	//������ 1���� �񱳰� �Ұ����ϹǷ� �� ���� ���� ��� �迭�� �־��ش�.
	if (i == half)
		result[index] = data[i];
	else
		result[index] = data[k];

	//�Է� �迭�� ������� �����Ѵ�.
	for (i = startIndex, k = 0; i <= endIndex; i++, k++)
	{
		data[i] = result[k];
	}

	return 0;
}

//�պ� ������ �����ϴ� �Լ�
int mergeSort(int data[], int amount)
{
	int retval;

	//��������
	//amount�� ¦���� �ƴϸ� �ߴ��Ѵ�.
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

//���� ������ �����ϴ� �Լ�
int selectSort(int data[], int amount)
{
	for (int i = 0; i < amount; i++)
	{
		//�ʿ��� ������ �����Ѵ�.
		int minValue = data[i];	//�ּڰ��� ����
		int index = i;		//�迭���� �ּڰ��� �ִ� ��ġ�� �ε����� ����

		for (int j = i; j < amount; j++)
		{
			//������ �ּڰ����� �� ���� ���� �ִٸ� �� ���� �����.
			if (data[j] < minValue)
			{
				minValue = data[j];
				index = j;
			}
		}

		//index�� ��ϵ� ��ġ�� �ּڰ��� �������� �̵��Ѵ�.
		int temp = data[i];
		data[i] = data[index];
		data[index] = temp;
	}

	return 0;
}

//�Ž������� ����ϴ� �Լ�
void coinChange(int input, int change[])
{
	//1000�� ������ ���ϰ� ���� ���� ���� ������� �ѱ��.
	change[0] = input / 1000;
	input %= 1000;

	//500�� ������ ���ϰ� ���� ���� ���� ������� �ѱ��.
	change[1] = input / 500;
	input %= 500;

	//100�� ������ ���ϰ� ���� ���� ���� ������� �ѱ��.
	change[2] = input / 100;
	input %= 100;

	//50�� ������ ���ϰ� ���� ���� ���� ������� �ѱ��.
	change[3] = input / 50;
	input %= 50;

	//10�� ������ ���ϰ� ���� ���� ���� ������� �ѱ��.
	change[4] = input / 10;
	input %= 10;

	//���� �� ������ ����� �迭�� �Ѱ��ش�.
	change[5] = input;
}