#include"Sort.h"

void TestInserSort()//÷±Ω”≤Â»Î≈≈–Ú
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	InserSort(a, sizeof(a)/sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));

}
void TestShellSort()//œ£∂˚≈≈–Ú
{
	int a[] = { 2,7,5,3,9,1,10,4,8,6 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
int main()
{
	//TestInserSort();
	TestShellSort();
	return 0;
}

