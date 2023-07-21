#include"Stack.h"


//初始化栈
void StackInit(ST* p)
{
	assert(p);
	p-> a = NULL;
	p-> top = p->capacity = 0;
}

//插入数据
void StackPush(ST* p, STDataType x)
{
	assert(p);
	if (p->top == p->capacity)
	{
		STDataType newCapacity = p->capacity == 0 ? 4 : 2 * p->capacity;
		STDataType* tmp = (STDataType*)realloc(p->a, 2 * sizeof(STDataType)* newCapacity);
		if (tmp == NULL)
		{
			printf("ralloc fail");
			exit(-1);
		}
		p->a = tmp;
		p->capacity = newCapacity;
	}
	p->a[p->top] = x;
	p->top++;
}

//删除数据
void StackPop(ST* p)
{
	assert(p&&!StackEmpty(p));
	p->top--;

}

//判空
bool StackEmpty(ST* p)
{
	assert(p);
	return p->top == 0;

}

//获取栈的大小
STDataType StackSize(ST* p)
{
	assert(p);
	return p->top;
}

//获取栈顶元素
STDataType StackTop(ST* p)
{
	assert(p&&!StackEmpty(p));
	return p->a[p->top-1];
}

//销毁栈
void StackDestroy(ST* p)
{
	assert(p);
	free(p->a);
	p->capacity = p->top = 0;

}
