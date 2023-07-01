#include"Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void InserSort(int* a, int n)
{
	//[0,end]���򣬰�end+1��λ�õ�ֵ���룬��������
	for (int i = 0; i<n-1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
	
}


//ʱ�临�Ӷ�ƽ��ΪO(N^1.3)
void ShellSort(int* a, int n)
{
	////����һ
	////���Ƚ���Ԥ����Ȼ���ٽ���ֱ�Ӳ�������
	//int gap = 3;
	//for (int j = 0; j < gap; j++)
	//{
	//	for (int i = j; i < n - gap; i += gap)
	//	{
	//		int end = i;
	//		int tmp = a[end + gap];
	//		while (end >= 0)
	//		{
	//			if (tmp < a[end])
	//			{
	//				a[end + gap] = a[end];
	//				end -= gap;
	//			}
	//			else
	//			{
	//				break;
	//			}
	//		}
	//		a[end + gap] = tmp;
	//	}
	//}
	

	//������
	//gap�����ݽ�����в�������
	//gap>1ʱ����Ԥ����
	//gap ���һ�ε���1����ֱ�Ӳ�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//��1��ȷ�����gap�Ľ���϶�Ϊ1
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}


void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;

			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}

		}
		Swap(&a[begin], &a[mini]);
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;

	}

}