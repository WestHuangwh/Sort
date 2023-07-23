#include"Sort.h"

void TestInserSort()//测试直接插入排序
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	InserSort(a, sizeof(a)/sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));

}
void TestShellSort()//测试希尔排序
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestSelectSort()//测试直接选择排序
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a,sizeof(a)/sizeof(a[0]));
	
}

void TestBubbleSort()//测试冒泡排序
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));

}

void TestQuickSort()//测试快速排序
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6};
	//int a2[] = { 2,7,5,3,9,1,10,4,8,6 ,99,95,44,36,29,45,67,93,299,333,222,356,569 };

	//QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);//递归

	QuickSortNonR(a, 0, sizeof(a) / sizeof(a[0]) - 1);//非递归 

	PrintArray(a, sizeof(a) / sizeof(a[0]));

}

void PrintQuickSortCount()//打印快速排序递归的次数
{
	printf("callCount:%d\n", callCount);
}

void TestMergeSort()
{
	int a[] = { 10,6,7,1,3,9,4,2};
	//int a[] = { 2,7,5,3,9,1,10,4,8,6 };

	//MergeSort(a, sizeof(a) / sizeof(a[0]));//递归的归并排序

	MergeSortNonR(a, sizeof(a) / sizeof(a[0]));//非递归的归并排序

	PrintArray(a, sizeof(a) / sizeof(a[0]));

}

int main()
{
	//TestInserSort();
	//TestShellSort();
	//TestSelectSort();
	//TestBubbleSort();
	//TestQuickSort();	
	//PrintQuickSortCount();//测试快速排序的递归调用次数
	TestMergeSort();

	return 0;
}

