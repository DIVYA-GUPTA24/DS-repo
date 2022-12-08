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
void traverse(struct node **start)
{
   struct node *p;
   p = (*start);
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
 void split(struct node **start)
 {
     struct node *t,*r;
     t=(*start);
     r=(*start)->next;
     while(r!=NULL && r->next!=NULL)
     {
         t=t->next;
         r=r->next;
         r=r->next;
     }
     (*start)=t->next;
     t->next=NULL;
     traverse(&(*start));
 }

int main()
{
   struct node *start;
   start = NULL;
   insbeg(&start, 8);
   insbeg(&start, 10);
   insbeg(&start, 20);
   insbeg(&start, 30);
   insbeg(&start, 40);
   insbeg(&start, 50);
   insbeg(&start, 60);
   traverse(&start);
   split(&start);
}
