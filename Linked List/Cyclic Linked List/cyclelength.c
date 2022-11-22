#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
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
int makecycle(struct node **start)
{
    struct node *p,*q;
    p=(*start);
    while(p->next!=NULL)
    {
        p=p->next;
    }
    printf("%d",p->info);
    q=(*start);
    while(q->info!=500)
    {
        q=q->next;
    }
    printf("%d",q->info);
    p->next=q;

}
int cycledetection(struct node **start)
{
    struct node *t,*r;
    t=(*start);
    r=(*start);
    int flag=0;
    while(r!=NULL && r->next!=NULL )
    {
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("cycle\n");
    }
    else
         printf("not a cycle\n");

    int c=0;
    do
    {
       t=t->next;
       c++;
    }
    while(t!=r);
    printf("The length of cycle is: %d", c);
     return 0;



}

int main()
{
   struct node *start;
   start = NULL;
   insbeg(&start, 200);
   insbeg(&start, 300);
   insbeg(&start, 400);
   insbeg(&start, 500);
   insbeg(&start, 600);
   insend(&start, 10);
   insend(&start, 20);
   insend(&start, 30);
   traverse(start);
   struct node *p,*q;
    p=start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    printf("%d ",p->info);
    q=start;
    while(q->info!=500)
    {
        q=q->next;
    }
    printf("%d ",q->info);
    p->next=q;
    cycledetection(&start);
}
