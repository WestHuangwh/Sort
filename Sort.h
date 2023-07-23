#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

//打印数组
void PrintArray(int* a, int n);

// 直接插入排序
void InserSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

//直接选择排序
void SelectSort(int* a, int n);

//堆排序
//void AddjustDown();//向下调整算法
void HeapSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

//快速排序
void QuickSort(int*a,int begin,int end);

//快速排序的非递归实现
void QuickSortNonR(int* a, int begin, int end);

//归并排序
void MergeSort(int* a, int n);

//归并排序的非递归实现
void MergeSortNonR(int* a, int n);

//声明变量
extern int callCount;