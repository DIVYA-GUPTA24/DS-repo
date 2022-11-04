#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10
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

void decimaltooctal(int y)
{
    int rem, a;
    initialize();
    while (y != 0)
    {
        rem = y % 8;
        push(rem);
        y = y / 8;
    }
    while (!isempty())
    {
        a = pop();
        printf("%d", a);
    }
}
int main()
{
    int y;
    scanf("%d", &y);
    decimaltooctal(y);
}
