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
 void pairwiseswap(struct node **start)
 {
     struct node *p,*q;
     p=(*start);
     q=(*start)->next;
     while(q!=NULL)
     {
         int x=p->info;
         p->info=q->info;
         q->info=x;
         p=p->next;
         p=p->next;
         q=q->next;
         if(q!=NULL)
         {
           q=q->next;
         }
     }
     traverse(&(*start));
 }

int main()
{
   struct node *start;
   start = NULL;
   insbeg(&start, 20);
   insbeg(&start, 30);
   insbeg(&start, 40);
   insbeg(&start, 50);
   traverse(&start);
   pairwiseswap(&start);
}
