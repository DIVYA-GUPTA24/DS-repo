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
int delaft(struct node *p)
{

   if (p == NULL || p->next == NULL)
   {
      printf("void deletion");
      exit;
   }
   struct node *q, *r;
   q = p->next;
   r = q->next;
   p->next = r;
   int x = q->info;
   free(q);
   return x;
}
int traverse(struct node *start)
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

struct node *Del_duplicate_nodes(struct node **start)
{
   struct node *p, *q, *r;
   p = (*start);
   r = (*start);
   q = (*start)->next;
   while (q != NULL)
   {

      while (q != NULL)
      {
         if (q->info == p->info)
         {
            q = q->next;
            delaft(r);
         }
         else
         {
            r = q;
            q = q->next;
         }
      }
      if (p->next != NULL)
      {
         p = p->next;
         r = p;
         q = p->next;
      }
      else
      {
         break;
      }
   }
   traverse(*start);
}

int main()
{
   struct node *start;
   start = NULL;
   insbeg(&start, 2);
   insbeg(&start, 2);
   insbeg(&start, 4);
   insbeg(&start, 6);
   insbeg(&start, 6);
   insbeg(&start, 2);
   insbeg(&start, 4);
   insbeg(&start, 2);
   insbeg(&start, 5);
   insbeg(&start, 4);
   insbeg(&start, 2);
   printf("Linked list: ");
   traverse(start);
   printf("Linked List after deleting duplicate nodes: ");
   Del_duplicate_nodes(&start);

   return 0;
}
