#include"Stack.h"


//��ʼ��ջ
void StackInit(ST* p)
{
	assert(p);
	p-> a = NULL;
	p-> top = p->capacity = 0;
}

//��������
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

//ɾ������
void StackPop(ST* p)
{
	assert(p&&!StackEmpty(p));
	p->top--;

}

//�п�
bool StackEmpty(ST* p)
{
	assert(p);
	return p->top == 0;

}

//��ȡջ�Ĵ�С
STDataType StackSize(ST* p)
{
	assert(p);
	return p->top;
}

//��ȡջ��Ԫ��
STDataType StackTop(ST* p)
{
	assert(p&&!StackEmpty(p));
	return p->a[p->top-1];
}

//����ջ
void StackDestroy(ST* p)
{
	assert(p);
	free(p->a);
	p->capacity = p->top = 0;

}
