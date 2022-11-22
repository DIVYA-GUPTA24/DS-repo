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
int concatenate(struct node **start1,struct node **start2)
{
   struct node *p;
   p=*start1;
   if((*start1)==NULL)
   {
       (*start1)=(*start2);
   }
   else{
   while(p->next!=NULL)
   {
      p=p->next;
    }
    p->next=*start2;
   }
   return (*start1);
}
int main()
{
   struct node *start1;
   struct node *start2;
   start1 = NULL;
   start2 = NULL;
    insbeg(&start1, 200);
   insbeg(&start1, 300);
   insbeg(&start1, 400);
   insbeg(&start1, 500);
   insbeg(&start2, 600);
   insbeg(&start2, 10);
   insbeg(&start2, 20);
   insbeg(&start2, 30);
   printf("first linked list: ");
   traverse(&start1);
   printf("\n");
    printf("second linked list: ");
      traverse(&start2);
    printf("\n");
    printf("After Concatenation: ");
    concatenate(&start1,&start2);
   traverse(&start1);
}
