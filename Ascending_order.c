#include<stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
struct node
{
   int info;
   struct node *next;
};

struct node *getnode()
{
   struct node *p;
   p = (struct node*)malloc(sizeof(struct node));
   return p;
}
void insbeg(struct node **start, int x)
{
   struct node *p;
   p = getnode();
   p->info = x;
   p->next = *start;
   *start = p;
}

void insend(struct node **start, int x)
{
   struct node *q;
   q = *start;
   while (q->next != NULL)
   {
      q = q->next;
   }
   struct node *p;
   p = getnode();
   p->info = x;
   p->next = NULL;
   q->next = p;
}
void traverse(struct node *start)
{
   struct node *p;
   p = start;
   while (p != NULL)
   {
      printf("%d ", p->info);
      p = p->next;
   }
   printf("\n");
}
void insaft(struct node *q, int x)
{
   struct node *r;
   struct node *p;
   r = q->next;
   p = getnode();
   p->info = x;
   p->next = r;
   q->next = p;
}
void orderedinsertion(struct node *start,int x)
{

    struct node *p,*q;
    p=start;
    q=NULL;
    while(p!=NULL && x>=p->info)
    {

        q=p;
        p=p->next;
    }
    if(q==NULL)
    {
        insbeg(&start,x);
    }
    else
    {
        insaft(q,x);
    }
}
int main()
{

   struct node *start;
   start = NULL;
   insbeg(&start, 50);
   insbeg(&start, 40);
   insbeg(&start, 30);
   insbeg(&start, 20);
   insbeg(&start, 10);
   insend(&start, 60);
   insend(&start, 70);
   insend(&start, 80);
   traverse(start);
   int x;
   scanf("%d",&x);
   orderedinsertion(start,x);
   traverse(start);
}
