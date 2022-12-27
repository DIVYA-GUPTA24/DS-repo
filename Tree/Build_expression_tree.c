#include <stdio.h>
#include <stdlib.h>

struct node
{
   char data;
   struct node *left;
   struct node *right;
   struct node *next;
};

struct node *makenode(char x)
{
   struct node *p;
   p = (struct node*)malloc(sizeof(struct node));
   p->data=x;
   p->left=NULL;
   p->right=NULL;
   p->next=NULL;
   return p;
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

struct node *BuildExpTree(char exp[])
{
    struct node *x,*y,*p,*q;
    struct node *START=NULL;
    char opstk[20];
    int top=-1;
    char symb,op;
    int i=0;
    while(exp[i]!='\0')
    {
        symb=exp[i];
        i++;
        if(symb>='a' && symb<='z' || symb>='A' && symb<='Z' || symb>='0' && symb<='9')
        {
            x=makenode(symb);
            x->next=START;
            START=x;
            //push(opndstk,op);
        }
        else{
            while(top!=-1 && prcd(opstk[top],symb))
            {
                //op=pop(opstk);
                op=opstk[top--];
                y=makenode(op);
                //a=pop(opndstk);
                p=START;
                START=START->next;
                //b=pop(opndstk);
                q=START;
                START=START->next;
                y->left=q;
                y->right=p;
                y->next=START;
                START=y;
                //push(opndstk,t);
            }
            opstk[++top]=symb;
            //push(opstk,symb);
        }
    }
    while(top!=-1)
    {
                op=opstk[top--];
                y=makenode(op);
                //a=pop(opndstk);
                p=START;
                START=START->next;
                //b=pop(opndstk);
                q=START;
                START=START->next;
                y->left=q;
                y->right=p;
                y->next=START;
                START=y;
                //push(opndstk,t);ss
    }
    return START;
}

void preordertraversal (struct node *t)
{
    if(t!=NULL)
    {
        printf("%c",t->data);
        preordertraversal(t->left);
        preordertraversal(t->right);
    }
}

void inordertraversal (struct node *t)
{
    if(t!=NULL)
    {
        inordertraversal(t->left);
        printf("%c",t->data);
        inordertraversal(t->right);
    }
}

void postordertraversal (struct node *t)
{
    if(t!=NULL)
    {
        postordertraversal(t->left);
        postordertraversal(t->right);
        printf("%c",t->data);
    }
}

int main()
{
    struct node *t;
    char exp[20];
    scanf("%s",&exp);
    t=BuildExpTree(exp);
    preordertraversal(t);
    printf("\n\n");
    inordertraversal(t);
    printf("\n\n");
    postordertraversal(t);

}
