#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// �������㸨������
int calculate(int num1, int num2, char op)
{
    switch (op)
    {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num2 != 0 ? num1 / num2 : 0; // ע�����Ϊ0�����
    default: return 0;
    }
}

// �����������ȼ�
int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// �����׺���ʽ��ֵ
int evaluatePostfix(const char* postfix)
{
    LinkStack numStack;
    initLStack(&numStack);
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            int num = 0;
            while (isdigit(postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            pushLStack(&numStack, num);
        }
        else if (postfix[i] == ' ' || postfix[i] == '\t')
        {
            i++; // �����հ��ַ�
        }
        else
        {
            int num2;
            popLStack(&numStack, &num2);
            int num1;
            popLStack(&numStack, &num1);
            int result = calculate(num1, num2, postfix[i]);
            pushLStack(&numStack, result);
            i++;
        }
    }
    int result;
    popLStack(&numStack, &result);
    destroyLStack(&numStack);
    return result;
}

// ����׺���ʽת��Ϊ��׺���ʽ
void convertToPostfix(const char* infix, char* postfix)
{


    // �������㸨������
    int calculate(int num1, int num2, char op);
    int priority(char op);

    // �����׺���ʽ��ֵ
    int evaluatePostfix(const char* postfix);

    // ����׺���ʽת��Ϊ��׺���ʽ
    void convertToPostfix(const char* infix, char* postfix)
    {
        LinkStack opStack;
        initLStack(&opStack);
        int postfixIndex = 0;

        for (int i = 0; infix[i] != '\0'; i++)
        {
            if (isdigit(infix[i]))
            {
                // ����ֱ���������׺���ʽ
                postfix[postfixIndex++] = infix[i];
            }
            else if (infix[i] == '(')
            {
                // ��������ջ
                pushLStack(&opStack, infix[i]);
            }
            else if (infix[i] == ')')
            {
                // ���������ţ�����ջ�����������ֱ������������
                while (!isEmptyLStack(&opStack) && getTopLStack(&opStack, &postfix[postfixIndex]) != '(')
                {
                    postfix[postfixIndex++] = ' ';
                    postfix[postfixIndex++] = popLStack(&opStack, &postfix[postfixIndex]);
                }
                // ����������
                if (!isEmptyLStack(&opStack))
                {
                    ElemType temp;
                    popLStack(&opStack, &temp);
                }
            }
            else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
            {
                // ���������
                while (!isEmptyLStack(&opStack) && priority(infix[i]) <= priority(opStack.top->data))
                {
                    postfix[postfixIndex++] = ' ';
                    postfix[postfixIndex++] = popLStack(&opStack, &postfix[postfixIndex]);
                }
                // ��ǰ�������ջ
                pushLStack(&opStack, infix[i]);
            }
            else if (infix[i] == ' ' || infix[i] == '\t')
            {
                // �����հ��ַ�
                continue;
            }
            else
            {
                // �Ƿ��ַ�
                printf("�Ƿ��ַ�: %c\n", infix[i]);
                destroyLStack(&opStack);
                return;
            }
        }

        // ���ʽɨ����ϣ���ջ��ʣ������������
        while (!isEmptyLStack(&opStack))
        {
            postfix[postfixIndex++] = ' ';
            postfix[postfixIndex++] = popLStack(&opStack, &postfix[postfixIndex]);
        }

        // ����ַ���������
        postfix[postfixIndex] = '\0';
        destroyLStack(&opStack);
    }


}

int main()
{
    char infix[256];
    printf("����������������ʽ��֧�����ţ���");
    scanf("%255s", infix);

    char postfix[256];
    convertToPostfix(infix, postfix);

    printf("��׺���ʽ��%s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("��������%d\n", result);

    return 0;
}

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// �������㸨������
int calculate(int num1, int num2, char op);
int priority(char op);

// �����׺���ʽ��ֵ
int evaluatePostfix(const char* postfix);

// ����׺���ʽת��Ϊ��׺���ʽ
void convertToPostfix(const char* infix, char* postfix);

// �����ʽ�Ƿ�Ϸ�
int isLegalExpression(const char* expr);

int main()
{
    char infix[256];
    printf("��ӭʹ�����������������\n");
    printf("����������������ʽ��֧�����ţ���������'exit'�˳���");

    while (1)
    {
        scanf("%255s", infix);
        if (strcmp(infix, "exit") == 0)
        {
            printf("��лʹ�ã��ټ���\n");
            break;
        }

        if (!isLegalExpression(infix))
        {
            printf("�Ƿ����ʽ�����������룺");
            continue;
        }

        char postfix[256];
        convertToPostfix(infix, postfix);

        if (postfix[0] == '\0')
        {
            printf("���ʽת��ʧ�ܣ����������룺");
            continue;
        }

        int result = evaluatePostfix(postfix);
        printf("��������%d\n", result);
        printf("��������һ�����ʽ��������'exit'�˳���");
    }

    return 0;
}

// �����ʽ�Ƿ�Ϸ�
int isLegalExpression(const char* expr)
{
    // ���������Ӹ����ӵ��߼��������ʽ�ĺϷ���
    // ���磬��������Ƿ�ƥ�䣬����������ֵ�λ���Ƿ���ȷ��
    // Ŀǰ������ֻ�Ǽ򵥵ؼ����ʽ�Ƿ�Ϊ��
    return strlen(expr) > 0;
}
