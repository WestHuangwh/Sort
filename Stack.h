#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType * a;
	STDataType top;//���ջ��
	STDataType capacity;//����

}ST;

//��ʼ��ջ
void StackInit(ST* p);

//��������
void StackPush(ST* p, STDataType x);

//ɾ������
void StackPop(ST* p);

//�п�
bool StackEmpty(ST* p);

//��ȡջ��Ԫ��
STDataType StackTop(ST* p);

//��ȡջ�Ĵ�С
STDataType StackSize(ST* p);

//����ջ
void StackDestroy(ST* p);
