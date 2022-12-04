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
void reverse(struct node **cstart)
{
    struct node *p,*c,*n;
    p=(*cstart);
    c=p->next;
    n=c->next;
    while(c!=(*cstart))
    {
        c->next=p;
        p=c;
        c=n;
        if(n!=(*cstart)->next)
        {
            n=n->next;
        }
    }
    c->next=p;
    (*cstart)=n;

}


void traverse(struct node **cstart)
{
   struct node *p,*q;
   p = (*cstart);
   q = (*cstart)->next;
   while (q != p)
   {
      printf("%d ", q->info);
      q = q->next;
   }
   printf("%d ", q->info);
   printf("\n");
}

int main()
{
   struct node *cstart;
   cstart = NULL;
   insbeg(&cstart, 200);
   insbeg(&cstart, 300);
   insbeg(&cstart, 400);
   insbeg(&cstart, 500);
   insbeg(&cstart, 600);

   traverse(&cstart);
   printf("linked list after reversing: ");
   reverse(&cstart);
   traverse(&cstart);
}

