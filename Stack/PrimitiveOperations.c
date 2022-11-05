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
    s.top=-1;
}
int isempty()
{
    if (s.top==-1)
       return true;
    else
       return false;
}
int push(int x)
{
    if (s.top==STACKSIZE-1)
    {
        printf("stack overflows");
        exit(1);
    }
    else
    {
        s.top=s.top+1;
        s.item[s.top]=x;
    }
}
int pop()
{
    int x;
    if(isempty(s))
    {
        printf("stack underflows");
        return 0;
    }
    else
    {
     x=s.item[s.top];
     s.top=s.top-1;
     return x;
    }
}
int main()
{
    int x;
    push(500);
    push(600);
    push(700);
    push(800);
    x=pop();
    printf("popped element is %d\n",x);
    x=pop();
    printf("popped element is %d\n",x);
return 0;
}

