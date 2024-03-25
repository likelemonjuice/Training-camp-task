#include "Stack.h"

// 初始化链栈
Status initLStack(LinkStack* s)
{
    if (s == NULL)
        return ERROR;
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

// 判断链栈是否为空
Status isEmptyLStack(LinkStack* s)
{
    if (s == NULL || s->top == NULL)
        return SUCCESS; // 栈为空
    return ERROR; // 栈不为空
}

// 获取栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e)
{
    if (s == NULL || s->top == NULL)
        return ERROR; // 栈为空
    *e = s->top->data;
    return SUCCESS;
}

// 清空链栈
Status clearLStack(LinkStack* s)
{
    if (s == NULL)
        return ERROR;
    while (!isEmptyLStack(s))
    {
        ElemType temp;
        popLStack(s, &temp);
    }
    return SUCCESS;
}

// 销毁链栈
Status destroyLStack(LinkStack* s)
{
    if (s == NULL)
        return ERROR;
    clearLStack(s);
    free(s);
    return SUCCESS;
}

// 获取链栈长度
Status LStackLength(LinkStack* s, int* length)
{
    if (s == NULL)
        return ERROR;
    *length = s->count;
    return SUCCESS;
}

// 入栈操作
Status pushLStack(LinkStack* s, ElemType data)
{
    if (s == NULL)
        return ERROR;
    LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));
    if (newNode == NULL)
        return ERROR; // 内存分配失败
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->count++;
    return SUCCESS;
}

// 出栈操作
Status popLStack(LinkStack* s, ElemType* data)
{
    if (s == NULL || s->top == NULL)
        return ERROR; // 栈为空
    *data = s->top->data;
    LinkStackPtr temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->count--;
    return SUCCESS;
}
