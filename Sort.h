#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//��ӡ����
void PrintArray(int* a, int n);

// ֱ�Ӳ�������
void InserSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

//ֱ��ѡ������
void SelectSort(int* a, int n);

//������
//void AddjustDown();//���µ����㷨
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

//��������
void QuickSort(int*a,int begin,int end);