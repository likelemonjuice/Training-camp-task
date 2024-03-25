#include "Stack.h"

// ��ʼ����ջ
Status initLStack(LinkStack* s)
{
    if (s == NULL)
        return ERROR;
    s->top = NULL;
    s->count = 0;
    return SUCCESS;
}

// �ж���ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s)
{
    if (s == NULL || s->top == NULL)
        return SUCCESS; // ջΪ��
    return ERROR; // ջ��Ϊ��
}

// ��ȡջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e)
{
    if (s == NULL || s->top == NULL)
        return ERROR; // ջΪ��
    *e = s->top->data;
    return SUCCESS;
}

// �����ջ
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

// ������ջ
Status destroyLStack(LinkStack* s)
{
    if (s == NULL)
        return ERROR;
    clearLStack(s);
    free(s);
    return SUCCESS;
}

// ��ȡ��ջ����
Status LStackLength(LinkStack* s, int* length)
{
    if (s == NULL)
        return ERROR;
    *length = s->count;
    return SUCCESS;
}

// ��ջ����
Status pushLStack(LinkStack* s, ElemType data)
{
    if (s == NULL)
        return ERROR;
    LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));
    if (newNode == NULL)
        return ERROR; // �ڴ����ʧ��
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
    s->count++;
    return SUCCESS;
}

// ��ջ����
Status popLStack(LinkStack* s, ElemType* data)
{
    if (s == NULL || s->top == NULL)
        return ERROR; // ջΪ��
    *data = s->top->data;
    LinkStackPtr temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->count--;
    return SUCCESS;
}
