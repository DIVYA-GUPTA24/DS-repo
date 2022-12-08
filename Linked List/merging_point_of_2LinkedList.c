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
int countingnodes(struct node **start)
{
    struct node *p;
    p=(*start);
    int count=0;
    while(p!=NULL)
    {
        p=p->next;
        count++;
    }
    return count;

}

 int mergingpoint(struct node **start,struct node **start2)
 {
     struct node *p,*q;
     p=(*start);
     q=(*start2);
     int m=countingnodes(&(*start));
     int n=countingnodes(&(*start2));
     if(m>n)
     {
     for(int i=0;i<m-n;i++)
     {
         p=p->next;
     }
     }
     else
     {
         if(n>m)
         {
            q=q->next;
         }
     }
     while(p!=q)
     {
         p=p->next;
         q=q->next;
     }
     if(p!=NULL)
     {
         printf("%d",p->info);
     }
     else
     {
         printf("merging point does not exist");
     }


 }



int main()
{
   struct node *start;
   start = NULL;
   insbeg(&start, 8);
   insbeg(&start, 7);
   insbeg(&start, 6);
   insbeg(&start, 5);
   insbeg(&start, 4);
   insbeg(&start, 3);
   insbeg(&start, 2);
   insbeg(&start, 1);
   printf("First linked list: ");
   traverse(&start);
   struct node *p,*q;
    p=start;
    while(p->info!=5)
    {
        p=p->next;
    }
    struct node *start2;
    start2=NULL;
    insbeg(&start2,10);
    insend(&start2,11);
    q=start2;
    while(q->next != NULL){
    q=q->next;
    }
    q->next=p;
    printf("Second linked list: ");
    traverse(&start2);
    printf("Merging point is: ");
    mergingpoint(&start,&start2);
}

