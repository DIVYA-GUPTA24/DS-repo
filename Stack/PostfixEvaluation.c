#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STACKSIZE 20
#define true 1
#define false 0

struct stack
{
    int item[STACKSIZE];
    int top;
};
struct stack s;
void initialize()
{
    s.top = -1;
}
int isempty()
{
    if (s.top == -1)
        return true;
    else
        return false;
}
void push(int x)
{
    if (s.top == STACKSIZE - 1)
    {
        printf("stack overflows");
        exit(1);
    }
    s.top = s.top + 1;
    s.item[s.top] = x;
}
int pop()
{
    int x;
    if (isempty(s))
    {
        printf("stack underflows");
        return 0;
    }
    else
    {
        x = s.item[s.top];
        s.top = s.top - 1;
        return x;
    }
}
int stacktop()
{
    int x=s.item[s.top];
    return x;
}
int evaluate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    case '%':
        return a % b;
        break;
    case '^':
        return pow(b,a);
        break;
    }
}
void infix(char ps[20])
{
    int x, i = 0, val, b, a;
    char symb;
    while (ps[i] != '\0')
    {
        symb = ps[i];
        if (symb >= '0' && symb <= '9')
            push(symb-'0');
        else
        {
            b = pop();
            a = pop();
            val = evaluate(a, b, symb);
            push(val);
        }
        i++;
    }
    x = pop();
    printf("%d", x);
}
int main()
{
    char ps[20];
    gets(ps);
    initialize();
    infix(ps);
}
