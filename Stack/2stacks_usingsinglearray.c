#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
int arr[SIZE];
int top2 = SIZE;
int top1 = -1;
void push1(int x)
{
    top1++;
    if (top2 - top1 == 0)
    {
        printf("stack overflows");
    }
    else
    arr[top1] = x;
}
void push2(int x)
{
    top2--;
    if (top2 - top1 == 0)
    {
        printf("stack overflows");
    }
    else
    arr[top2] = x;
}
int pop1()
{
    if (top1 == -1)
    {
        printf("stack underflows");
    }
    else
    {
        int y = arr[top1];
        top1--;
        return y;
    }
    return 0;
}
int pop2()
{

    if (top2 == SIZE)
    {
        printf("stack underflows");
    }
    else
    {
        int y = arr[top2];
        top2++;
        return y;
    }
    return 0;
}

int main()
{
    push1(32);
    push2(66);
    push1(72);
    push2(45);
    printf("\n%d",pop2());
    printf("\n%d",pop2());
    push2(39);
    push1(55);
    push2(24);
    printf("\n%d", pop2());
    printf("\n%d", pop1());
    printf("\n%d", pop1());
}
