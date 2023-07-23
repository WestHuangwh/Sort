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
	int a[] = { 2,7,5,3,9,1,10,4,8,6};
	//int a2[] = { 2,7,5,3,9,1,10,4,8,6 ,99,95,44,36,29,45,67,93,299,333,222,356,569 };

	//QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);//�ݹ�

	QuickSortNonR(a, 0, sizeof(a) / sizeof(a[0]) - 1);//�ǵݹ� 

	PrintArray(a, sizeof(a) / sizeof(a[0]));

}

void PrintQuickSortCount()//��ӡ��������ݹ�Ĵ���
{
	printf("callCount:%d\n", callCount);
}

void TestMergeSort()
{
	int a[] = { 10,6,7,1,3,9,4,2};
	//int a[] = { 2,7,5,3,9,1,10,4,8,6 };

	//MergeSort(a, sizeof(a) / sizeof(a[0]));//�ݹ�Ĺ鲢����

	MergeSortNonR(a, sizeof(a) / sizeof(a[0]));//�ǵݹ�Ĺ鲢����

	PrintArray(a, sizeof(a) / sizeof(a[0]));

}

int main()
{
	//TestInserSort();
	//TestShellSort();
	//TestSelectSort();
	//TestBubbleSort();
	//TestQuickSort();	
	//PrintQuickSortCount();//���Կ�������ĵݹ���ô���
	TestMergeSort();

	return 0;
}

