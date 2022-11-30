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
int delbeg(struct node **start)
{
    if(start==NULL)
    {
        printf("void deletion");
        exit(1);
    }
    struct node *p;
    p=*start;
    *start=(*start)->next;
    int x=p->info;
    free(p);
    return x;

}
int delaft(struct node **p)
{
    struct node *q,*r;
    if((*p)==NULL|| (*p)->next==NULL)
    {
        printf("void deletion");
        return -1;

    }
    q=(*p)->next;
    int x=q->info;
    r=q->next;
    (*p)->next=r;
    free(q);
    return x;

}
int delend(struct node *start)
{
    struct node*p,*q;
    p=start;
    q=NULL;
    while(p->next!=NULL)
    {

        q=p;
        p=p->next;
    }
    q->next=NULL;
    int x=p->info;
    free(p);
    return x;

}
int reverse(struct node **start1){
    struct node *p,*c,*n;
    p=NULL;
    c=(*start1);
    n=c->next;
    while (c!=NULL)
    {
        c->next=p;
        p=c;
        c=n;
        if (n!=NULL)
        {
            n=n->next;
        }
    }
    (*start1)=p;

}



void addof2no(struct node **start1,struct node **start2)
{
    struct node *p,*q,*start;
    int total,sum,carry;
    reverse(&(*start1));
    reverse(&(*start2));
    p=(*start1);
    q=(*start2);
    start=NULL;
    while(p!=NULL && q!=NULL)
    {
         total=p->info+q->info+carry;
         sum=total%10;
         carry=total/10;
         p=p->next;
         q=q->next;
         insbeg(&start,sum);
    }
    while(p!=NULL)
    {
        total=p->info+carry;
        sum=total%10;
        carry=total/10;
        p=p->next;
        insbeg(&start,sum);

    }
        while(q!=NULL)
    {
        total=q->info+carry;
        sum=total%10;
        carry=total/10;
        q=q->next;
        insbeg(&start,sum);

    }
    if(carry>0)
    {
        insbeg(&start,carry);
    }
    traverse(&start);




}

int main()
{
   struct node *start1=NULL;
   insbeg(&start1, 5);
   insbeg(&start1, 2);
   insbeg(&start1, 1);


   printf("The 1st linked list is: ");
   traverse(&start1);
   struct node *start2=NULL;
   insbeg(&start2, 5);
   insbeg(&start2, 8);
   printf("The 2nd linked list is: ");
   traverse(&start2);
   printf("addition of both linked list: ");
   addof2no(&start1,&start2);

}

