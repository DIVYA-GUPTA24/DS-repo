#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10
#define true 1
#define false 0

struct stack
{
    char item[STACKSIZE];
    int top;
};

void initialise(struct stack *s)
{
    s->top=-1;
}
int isempty(struct stack *s)
{
    if (s->top==-1)
       return true;
    else
       return false;
}
int push(struct stack *s,char x)
{
    if (s->top==STACKSIZE-1)
    {
        printf("stack overflows");
        exit(1);
    }
    else
    {
        s->top=s->top+1;
        s->item[s->top]=x;
    }
}
char pop(struct stack *s)
{
    char x;
    if(isempty(&s))
    {
        printf("stack underflows");
        return 0;
    }
    else
    {
     x=s->item[s->top];
     s->top=s->top-1;
     return x;
    }
}

int main()
{
    struct stack S;
    initialise(&S);
    char x;
    push(&S,'A');
    push(&S,'B');
    push(&S,'C');
    push(&S,'D');
    x=pop(&S);
    printf("popped element is %c\n",x);
    x=pop(&S);
    printf("popped element is %c\n",x);
return 0;
}

