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
   p = (struct node *)malloc(sizeof(struct node));
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
struct node *middleelement(struct node **start)
{
   struct node *t, *r;
   t = (*start);
   r = (*start)->next;
   while (r != NULL && r->next != NULL)
   {
      t = t->next;
      r = r->next;
      r = r->next;
   }
   return t;
}
void binarysearch(struct node **start, int x)
{

   while ((*start)->next != NULL)
   {
      struct node *m;
      m = middleelement(&(*start));
      if (m->info == x)
      {
         printf("%d", m->info);
         exit(1);
      }
      else if (m->info < x)
      {
         (*start) = m->next;
      }
      else
      {
         m->next = NULL;
      }
   }
   if ((*start)->info == x)
   {
      printf("%d", (*start)->info);
   }
   else
   {
      printf("ELement not found");
   }
}

int main()
{
   struct node *start;
   start = NULL;
   insbeg(&start, 20);
   insbeg(&start, 10);
   insend(&start, 30);
   insend(&start, 50);
   insend(&start, 60);
   insend(&start, 70);
   traverse(start);

   int x;
   scanf("%d", &x);
   printf("Element info after bineary search: ");
   binarysearch(&start, x);
}
