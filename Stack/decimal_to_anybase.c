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

void decimaltoanybasedecimal(int y,int base)
{
    int rem, a;
    char conv[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    initialize();
    while (y != 0)
    {
        rem = y % base;
        push(rem);
        y = y / base;
    }
    while (!isempty())
    {
        a = pop();
        printf("%c", conv[a]);
    }
}
int main()
{
    int y,x;
    scanf("%d", &y);
    decimaltoanybasedecimal(y,2);
}
