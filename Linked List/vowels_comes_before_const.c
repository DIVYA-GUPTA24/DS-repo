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
   p = (struct node *)malloc(sizeof(struct node));
   return p;
}
void insbeg(struct node **start, char x)
{
   struct node *p;
   p = getnode();
   p->info = x;
   p->next = *start;
   *start = p;
}

void insend(struct node **start, char x)
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
void insaft(struct node *q, char x)
{
   struct node *r;
   struct node *p;
   r = q->next;
   p = getnode();
   p->info = x;
   p->next = r;
   q->next = p;
}
int delbeg(struct node **start)
{
   if ((*start) == NULL)
   {
      printf("void deletion");
      exit(1);
   }
   struct node *p;
   p = (*start);
   (*start) = (*start)->next;
   int x = p->info;
   free(p);
   return x;
}
int delaft(struct node *p)
{
   struct node *q, *r;
   if (p == NULL || p->next == NULL)
   {
      printf("void deletion");
      return -1;
   }
   q = p->next;
   int x = q->info;
   r = q->next;
   p->next = r;
   free(q);
   return x;
}
void arrange(struct node **start)
{
   struct node *p, *q, *r;
   p = NULL;
   r = NULL;
   q = (*start);
   char x;
   while (q != NULL)
   {
      if (q->info == 'A' || q->info == 'E' || q->info == 'I' || q->info == 'O' || q->info == 'U')
      {
         q = q->next;
         if (p == NULL)
         {
            if (r != NULL)
            {
               x = delaft(r);
               insbeg(&(*start), x);
               p = (*start);
            }
            else
            {

               x = delbeg(&(*start));
               insbeg(&(*start), x);
               p = (*start);
               r=p;
            }
         }
         else
         {
            x = delaft(r);
            insaft(p, x);
            if (r == p)
            {
               r = r->next;
            }
            p = p->next;
         }
      }
      else
      {
         r = q;
         q = q->next;
      }
   }
}

void traverse(struct node **start)
{
   struct node *p;
   p = (*start);
   while (p != NULL)
   {
      printf("%c ", p->info);
      p = p->next;
   }
   printf("\n");
}

int main()
{
   struct node *start;
   char x;
   start = NULL;
   insbeg(&start, 'A');
   insbeg(&start, 'I');
   insbeg(&start, 'U');
   insbeg(&start, 'Y');
   insbeg(&start, 'A');

   printf("Linked List before arranging: ");
   traverse(&start);
   printf("Linked List after arranging: ");
   arrange(&start);
   traverse(&start);
   return 0;
}
