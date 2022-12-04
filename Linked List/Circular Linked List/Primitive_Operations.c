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
void insbeg(struct node **cstart, int x)
{
   struct node *p;
   p = getnode();
   p->info = x;
   if((*cstart)!=NULL)
   {
        p->next = (*cstart)->next;
        (*cstart)->next = p;
   }
   else
    {
        (*cstart)=p;
        (*cstart)->next=p;
   }
}

void insend(struct node **cstart, int x)
{
   struct node *p;
   p = getnode();
   p->info = x;
   if(*cstart!=NULL)
   {
       p->next = (*cstart)->next;
       (*cstart)->next=p;
       (*cstart)=p;
    }
}
int insaft(struct node *q, int x)
{

   struct node *p;
   p = getnode();
   p->info = x;
   p->next = q->next;
   q->next = p;


}
int delbeg(struct node **cstart)
{
   struct node *p;
   p=(*cstart)->next;
   (*cstart)->next=p->next;
   if((*cstart)->next==(*cstart))
   {
       (*cstart)=NULL;
   }
   int x=p->info;
   free(p);
   return x;


}
int delend(struct node **cstart)
{
    struct node *p,*q;
    p=(*cstart);
    q=(*cstart)->next;

    while(q->next!=(*cstart))
    {
        q=q->next;
    }
    q->next=(*cstart)->next;
    (*cstart)=q;
    int x=(*cstart)->info;
    free(p);
    return x;


}

int delaft(struct node **cstart,struct node *p)
{
   struct node *q;
   q=p->next;
   int x=q->info ;
   if(q==(*cstart))
   {
       (*cstart)=p;
   }
   p->next=q->next;
   free(q);
   return x;


}

void traverse(struct node *cstart)
{
   struct node *p,*q;
   p = cstart;
   q = cstart->next;
   while (q != p)
   {
      printf("%d ", q->info);
      q = q->next;
   }
   printf("%d ", q->info);
   printf("\n");
}

int count(struct node **cstart)
{
    struct node *p,*q;
    p=(*cstart);
    q=(*cstart)->next;
    int c=0;
    while(q!=p)
    {
        c++;
        q=q->next;

    }
    return c;

}



int main()
{
   struct node *cstart,*q;
   cstart = NULL;
   insbeg(&cstart, 200);
   insbeg(&cstart, 300);
   insbeg(&cstart, 400);
   insbeg(&cstart, 500);
   insbeg(&cstart, 600);
   insend(&cstart, 700);

   traverse(cstart);

   delbeg(&cstart);

   traverse(cstart);
   delend(&cstart);
   traverse(cstart);
   q=cstart;
   int d;
   printf("enter the position: ");
   scanf("%d",&d);

   for(int i=1;i<d+1;i++)
   {
       q=q->next;
   }

   delaft(&cstart,q);

   printf("Final linked list: ");
   traverse(cstart);
   return 0;

}
