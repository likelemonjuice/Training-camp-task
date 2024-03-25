#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 四则运算辅助函数
int calculate(int num1, int num2, char op)
{
    switch (op)
    {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num2 != 0 ? num1 / num2 : 0; // 注意除数为0的情况
    default: return 0;
    }
}

// 检查运算符优先级
int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 计算后缀表达式的值
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
            i++; // 跳过空白字符
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

// 将中缀表达式转换为后缀表达式
void convertToPostfix(const char* infix, char* postfix)
{


    // 四则运算辅助函数
    int calculate(int num1, int num2, char op);
    int priority(char op);

    // 计算后缀表达式的值
    int evaluatePostfix(const char* postfix);

    // 将中缀表达式转换为后缀表达式
    void convertToPostfix(const char* infix, char* postfix)
    {
        LinkStack opStack;
        initLStack(&opStack);
        int postfixIndex = 0;

        for (int i = 0; infix[i] != '\0'; i++)
        {
            if (isdigit(infix[i]))
            {
                // 数字直接输出到后缀表达式
                postfix[postfixIndex++] = infix[i];
            }
            else if (infix[i] == '(')
            {
                // 左括号入栈
                pushLStack(&opStack, infix[i]);
            }
            else if (infix[i] == ')')
            {
                // 遇到右括号，弹出栈内所有运算符直到遇到左括号
                while (!isEmptyLStack(&opStack) && getTopLStack(&opStack, &postfix[postfixIndex]) != '(')
                {
                    postfix[postfixIndex++] = ' ';
                    postfix[postfixIndex++] = popLStack(&opStack, &postfix[postfixIndex]);
                }
                // 弹出左括号
                if (!isEmptyLStack(&opStack))
                {
                    ElemType temp;
                    popLStack(&opStack, &temp);
                }
            }
            else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
            {
                // 运算符处理
                while (!isEmptyLStack(&opStack) && priority(infix[i]) <= priority(opStack.top->data))
                {
                    postfix[postfixIndex++] = ' ';
                    postfix[postfixIndex++] = popLStack(&opStack, &postfix[postfixIndex]);
                }
                // 当前运算符入栈
                pushLStack(&opStack, infix[i]);
            }
            else if (infix[i] == ' ' || infix[i] == '\t')
            {
                // 跳过空白字符
                continue;
            }
            else
            {
                // 非法字符
                printf("非法字符: %c\n", infix[i]);
                destroyLStack(&opStack);
                return;
            }
        }

        // 表达式扫描完毕，将栈中剩余的运算符弹出
        while (!isEmptyLStack(&opStack))
        {
            postfix[postfixIndex++] = ' ';
            postfix[postfixIndex++] = popLStack(&opStack, &postfix[postfixIndex]);
        }

        // 添加字符串结束符
        postfix[postfixIndex] = '\0';
        destroyLStack(&opStack);
    }


}

int main()
{
    char infix[256];
    printf("请输入四则运算表达式（支持括号）：");
    scanf("%255s", infix);

    char postfix[256];
    convertToPostfix(infix, postfix);

    printf("后缀表达式：%s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("计算结果：%d\n", result);

    return 0;
}

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 四则运算辅助函数
int calculate(int num1, int num2, char op);
int priority(char op);

// 计算后缀表达式的值
int evaluatePostfix(const char* postfix);

// 将中缀表达式转换为后缀表达式
void convertToPostfix(const char* infix, char* postfix);

// 检查表达式是否合法
int isLegalExpression(const char* expr);

int main()
{
    char infix[256];
    printf("欢迎使用四则运算计算器。\n");
    printf("请输入四则运算表达式（支持括号），或输入'exit'退出：");

    while (1)
    {
        scanf("%255s", infix);
        if (strcmp(infix, "exit") == 0)
        {
            printf("感谢使用，再见！\n");
            break;
        }

        if (!isLegalExpression(infix))
        {
            printf("非法表达式，请重新输入：");
            continue;
        }

        char postfix[256];
        convertToPostfix(infix, postfix);

        if (postfix[0] == '\0')
        {
            printf("表达式转换失败，请重新输入：");
            continue;
        }

        int result = evaluatePostfix(postfix);
        printf("计算结果：%d\n", result);
        printf("请输入下一个表达式，或输入'exit'退出：");
    }

    return 0;
}

// 检查表达式是否合法
int isLegalExpression(const char* expr)
{
    // 这里可以添加更复杂的逻辑来检查表达式的合法性
    // 例如，检查括号是否匹配，运算符和数字的位置是否正确等
    // 目前，我们只是简单地检查表达式是否为空
    return strlen(expr) > 0;
}
