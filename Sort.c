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

//����������
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;

}

// O (N^2)
//ѡ������ԱȲ������򣬷����ǲ����������
void SelectSort(int* a, int n)
{
	assert(a);//���Լ���Ƿ�Ϊ��ָ��
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
		//���begin��maxi�ص�����ôҪ����һ��maxi��λ��
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}

}

//ʱ�临�Ӷȣ�O(N^2)    ��õ������O(N)
//�Ա� ��������˭���ã�-- ����
void BubbleSort(int* a, int n)
{
	assert(a);//���Լ���Ƿ�Ϊ��
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



//-------------���������Լ���������ļ����Ż�����---------------

//Hoare  �����汾�Ŀ�������
int PartSort1(int* a, int begin, int end)
{
	int left = begin;
	int right = end;
	int keyi = left;
	while (left < right)
	{
		//�ұ����ߣ���С
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		//������ߣ��Ҵ� 
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

//�ڿӷ��Ŀ�������
int PartSort2(int* a, int begin, int end)
{
	int key = a[begin];
	int piti = begin;
	while (begin < end)
	{
		//�ұ���С�����ߵĿ���ȥ�����λ���γ��µĿ�
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[piti] = a[end];
		piti = end;

		//����Ҵ���ұߵĿ���ȥ�����λ���γ��µĿ�
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

//ǰ��ָ�뷨�Ŀ�������
int PartSort3(int* a, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int keyi = begin;

	while (cur <= end)
	{
		//curλ�õ�ֵС��keyiλ�õ�ֵ
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
	//���䲻���ڣ�����ֻ��һ��ֵ����Ҫ�ٴ��� 
	if (begin >= end)
	{
		return;
	}

	int keyi = PartSort3(a, begin, end);

	//[begin,keyi-1] keyi [keyi+1,end]
	QuickSort(a, begin, keyi-1);
	QuickSort(a, keyi+1, end);

}


