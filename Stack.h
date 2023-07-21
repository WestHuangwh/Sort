#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType * a;
	STDataType top;//标记栈顶
	STDataType capacity;//容量

}ST;

//初始化栈
void StackInit(ST* p);

//插入数据
void StackPush(ST* p, STDataType x);

//删除数据
void StackPop(ST* p);

//判空
bool StackEmpty(ST* p);

//获取栈顶元素
STDataType StackTop(ST* p);

//获取栈的大小
STDataType StackSize(ST* p);

//销毁栈
void StackDestroy(ST* p);
