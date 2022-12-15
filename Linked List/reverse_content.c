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

void print_reverse(struct node *start)
{
     struct node *p;
     p=(start);
     if(p!=NULL)
     {
         print_reverse(start->next);
         printf("%d ",p->info);
     }
}

int main()
{
   struct node *start;
   start = NULL;
   insbeg(&start, 20);
   insbeg(&start, 30);
   insbeg(&start, 40);
   insbeg(&start, 50);
   insbeg(&start, 60);
   insbeg(&start, 70);
   printf("before reversing the content: ");
   traverse(start);
   printf("after reversing the content: ");
   print_reverse(start);
}
