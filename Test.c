#include"Sort.h"

void TestInserSort()//直接插入排序
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	InserSort(a, sizeof(a)/sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));

}
void TestShellSort()//希尔排序
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
void TestSelectSort()//直接选择排序
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a,sizeof(a)/sizeof(a[0]));

}

int main()
{
	//TestInserSort();
	//TestShellSort();
	TestSelectSort();
	return 0;
}

