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
char stacktop()
{
    char x=s.item[s.top];
    return x;
}


int prcd(char a, char b)
{
    if(a=='(' || b=='(' )
         return 0;
    if(a!='(' && b==')')
        return 1;
    else if(a=='(' && b==')')
        return 0;
    else if (a == '^' || a == '*' || a == '/' || a == '%')
    {
        if (b == '^')
            return 0;
        else
            return 1;
    }
    else
    {
        if (b == '+' || b == '-')
            return 1;
        else
            return 0;
    }
}


void infixtopostfix(char infix[])
{
    int i = 0, p = 0;
    char postfixexp[20];
    char x,y,symbol;
    while (infix[i]!='\0')
    {
        symbol = infix[i];
        if (symbol >= 'a' && symbol <= 'z')
        {
            postfixexp[p] = symbol;
            p++;
        }

        else
        {
            while (!isempty() && prcd(stacktop(), symbol))
            {
                x = pop();
                postfixexp[p] = x;
                p++;
            }
            if(symbol!=')')
            {
                push(symbol);
            }
            else
                pop();
        }
        i++;
    }
    while(!isempty())
    {
        y=pop();
        postfixexp[p]=y;
        p++;
    }
    postfixexp[p]='\0';
    printf("%s",postfixexp);
}
int main()
{
    initialize();
    char infix[20];
    scanf("%s",infix);
    infixtopostfix(infix);
}

