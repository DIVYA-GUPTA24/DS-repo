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
   if(q==NULL)
   {
       printf("void insertion");
       return -1;
   }
   else
    {
   p = getnode();
   p->info = x;
   p->next = q->next;
   q->next = p;
    }

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
void pattern(struct node **cstart)
{
    struct node *r,*q;
    r=(*cstart)->next;
    int total=0;
    while(r!=(*cstart))
    {
        total+=r->info;
        r=r->next;
    }
    total=total+r->info;
    q=(*cstart)->next;
    while(q!=(*cstart))
    {
        q->info=total-(q->info);
        q=q->next;
    }
    q->info=total-(q->info);
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
   struct node *cstart1,*cstart2;
   cstart1 = NULL;

   insbeg(&cstart1, 30);
   insbeg(&cstart1, 70);
   insbeg(&cstart1, 50);
   insbeg(&cstart1, 10);
   traverse(cstart1);

   pattern(&cstart1);
   traverse(cstart1);
   return 0;
}


