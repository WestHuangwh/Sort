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
	//[0,end]有序，把end+1的位置的值插入，保持有序
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


//时间复杂度平均为O(N^1.3)
void ShellSort(int* a, int n)
{
	////方法一
	////首先进行预排序，然后再进行直接插入排序
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
	

	//方法二
	//gap组数据交替进行插入排序
	//gap>1时，是预排序
	//gap 最后一次等于1，是直接插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//加1是确保最后gap的结果肯定为1
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

//交换两个数
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;

}

// O (N^2)
//选择排序对比插入排序，发现是插入排序更好
void SelectSort(int* a, int n)
{
	assert(a);//断言检查是否为空指针
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
		//如果begin和maxi重叠，那么要修正一下maxi的位置
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}

}

//时间复杂度：O(N^2)    最好的情况：O(N)
//对比 插入排序，谁更好？-- 插入
void BubbleSort(int* a, int n)
{
	assert(a);//断言检查是否为空
	for (int j = 0; j < n; j++)
	{
		int exchange = 0;
		for (int i = 1; i < n-j; i++)
		{
			if (a[i-1] > a[i])
			{
				Swap(&a[i-1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}

}



//-------------快速排序以及快速排序的几种优化方法---------------

//Hoare  霍尔版本的快速排序
int PartSort1(int* a, int begin, int end)
{
	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)
	{
		//右边先走，找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		//左边再走，找大 
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	keyi = left;
	return keyi;
}

//挖坑法的快速排序
int PartSort2(int* a, int begin, int end)
{
	int key = a[begin];
	int piti = begin;
	while (begin < end)
	{
		//右边找小，填到左边的坑里去。这个位置形成新的坑
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[piti] = a[end];
		piti = end;

		//左边找大，填到右边的坑里去，这个位置形成新的坑
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[piti] = a[begin];
		piti = begin;
	}
	a[piti] = key;
	return piti;
}

//前后指针法的快速排序
int PartSort3(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;

	while (cur <= end)
	{
		//cur位置的值小于keyi位置的值
		if (a[cur] < a[keyi]&& ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}

		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	return keyi;
}

void QuickSort(int* a, int begin,int end)
{
	//区间不存在，或者只有一个值不需要再处理 
	if (begin >= end)
	{
		return;
	}

	int keyi = PartSort3(a, begin, end);

	//[begin,keyi-1] keyi [keyi+1,end]
	QuickSort(a, begin, keyi-1);
	QuickSort(a, keyi+1, end);

}


