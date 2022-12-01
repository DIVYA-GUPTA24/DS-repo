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
void concatenate(struct node **cstart1,struct node **cstart2)
{

    struct node *p,*q;
    p=(*cstart1)->next;
    q=(*cstart2)->next;
    (*cstart1)->next=q;
    (*cstart2)->next=p;
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
   insbeg(&cstart1, 200);
   insbeg(&cstart1, 300);
   insbeg(&cstart1, 400);
   insbeg(&cstart1, 500);
   insbeg(&cstart1, 600);
   traverse(cstart1);

   cstart2 = NULL;
   insbeg(&cstart2, 10);
   insbeg(&cstart2, 20);
   insbeg(&cstart2, 30);
   insbeg(&cstart2, 40);
   insbeg(&cstart2, 50);
   traverse(cstart2);

   concatenate(&cstart1,&cstart2);
   traverse(cstart2);
   return 0;
}

