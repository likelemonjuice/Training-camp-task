#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// ����״̬ö��
typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

// ����Ԫ������
typedef int ElemType;

// ����ջ�ڵ�ṹ
typedef struct StackNode
{
    ElemType data;
    struct StackNode* next;
} StackNode, * LinkStackPtr;

// ������ջ�ṹ
typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
} LinkStack;

// ��ջ������������
Status initLStack(LinkStack* s);
Status isEmptyLStack(LinkStack* s);
Status getTopLStack(LinkStack* s, ElemType* e);
Status clearLStack(LinkStack* s);
Status destroyLStack(LinkStack* s);
Status LStackLength(LinkStack* s, int* length);
Status pushLStack(LinkStack* s, ElemType data);
Status popLStack(LinkStack* s, ElemType* data);

#endif // STACK_H_INCLUDED
#pragma once
