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
   struct node *p = start;
   int d;
   scanf("%d", &d);
   for (int i = 1; i < d-1; i++)
   {
      p = p->next;
   }
   insaft(p, 67);
   traverse(start);
}
