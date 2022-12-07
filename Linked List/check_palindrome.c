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

void reverse(struct node **start)
{
    struct node *start2,*p,*q;
    start2=NULL;
    p=(*start);
    while(p!=NULL)
    {
        insbeg(&start2,p->info);
        p=p->next;
    }
    traverse(&start2);

   p=(*start);
   q=start2;
   int flag=0;
    while(p!=NULL && q!=NULL)
   {
   if(p->info==q->info)
   {
      p=p->next;
      q=q->next;
      flag=1;
   }
   else{
        flag=0;
       break;
   }

   }

   if(flag==1)
   {
       printf("palindrome");

   }
   else{
    printf("not a palindrome");
   }
}

int main()
{
   struct node *start,*start2;
   start = NULL;
   insbeg(&start, 2);
   insbeg(&start, 0);
   insbeg(&start, 0);
   insbeg(&start, 2);

   traverse(&start);
   printf("linked list after reversing: ");
   reverse(&start);

}
