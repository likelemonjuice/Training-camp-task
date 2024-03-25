#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// 定义状态枚举
typedef enum Status
{
    ERROR = 0,
    SUCCESS = 1
} Status;

// 定义元素类型
typedef int ElemType;

// 定义栈节点结构
typedef struct StackNode
{
    ElemType data;
    struct StackNode* next;
} StackNode, * LinkStackPtr;

// 定义链栈结构
typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
} LinkStack;

// 链栈操作函数声明
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
