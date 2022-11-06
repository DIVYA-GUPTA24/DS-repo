#include <stdlib.h>
#include <stdio.h>
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
void push(int x)
{
    if (s.top == (STACKSIZE - 1))
    {
        printf("stack overflows");
        return;
    }
    s.top = s.top + 1;
    s.item[s.top] = x;
}
char pop()
{
    char x;
    if (s.top==-1)
    {
        printf("stack underflows");
        return 0;
    }
    x = s.item[s.top];
    s.top = s.top - 1;
    return x;
}


int isempty()
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}

void validparenthesis(char exp[20])
{
    int flag=1;
    int i=0;
    while(exp[i]!='\0')
    {
        if(exp[i]=='(')
            push(exp[i]);
        else
        {
            if(isempty())
            {
                flag=0;
                break;
            }
            pop();
        }
        i++;

    }
    if(flag==1)
    {
        if(!isempty())
            printf("incorrect expression");
        else
            printf("correct expression");
    }
    else
          printf("incorrect expression");



}
int main()
{

    char exp[20];
    gets(exp);
    initialize();
    validparenthesis(exp);
}

