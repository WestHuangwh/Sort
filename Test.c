#include"Sort.h"

void TestInserSort()//����ֱ�Ӳ�������
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	InserSort(a, sizeof(a)/sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));

}
void TestShellSort()//����ϣ������
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestSelectSort()//����ֱ��ѡ������
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a,sizeof(a)/sizeof(a[0]));
	
}

void TestBubbleSort()//����ð������
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));

}

void TestQuickSort()//���Կ�������
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	PrintArray(a, sizeof(a) / sizeof(a[0]));

}

int main()
{
	//TestInserSort();
	//TestShellSort();
	//TestSelectSort();
	//TestBubbleSort();
	TestQuickSort();	
	return 0;
}

