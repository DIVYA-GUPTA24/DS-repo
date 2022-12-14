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
   p->next = (*start);
   (*start) = p;
}

void insend(struct node **start, int x)
{
   struct node *q, *p;
    q = *start;
    p = getnode();
    p->info = x;
    p->next = NULL;
    if (q == NULL)
    {
        (*start) = p;
    }
    else
    {
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}
void traverse(struct node *start)
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
int delaft(struct node *q)
{
    struct node *p;
    if(p==NULL|| p->next==NULL)
    {
        printf("void deletion");
        exit(1);

    }

    struct node *r;
    q=p->next;
    r=q->next;
    p->next=r;
    int x=q->info;
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
int count(struct node *start)
{
    struct node *p;
    p=start;
    int c=0;
    while(p!=NULL)
    {
        c++;
        p=p->next;

    }
    return c;

}


int main()
{
   struct node *start;
   start = NULL;
   insbeg(&start, 200);
   insbeg(&start, 300);
   insbeg(&start, 400);
   insbeg(&start, 500);
   insbeg(&start, 600);
   insend(&start, 10);
   insend(&start, 20);
   insend(&start, 30);
   traverse(start);
   struct node *p=start;
   int d;
   printf("Enter position: ");
   scanf("%d",&d);
   int c=count(start);
   if(d==1)
   {
       insbeg(&start,67);
   }
   else if(d>c+1)
   {
        printf("void insertion");
   }
   else
   {
       for(int i=1;i<d-1;i++)
         {
            p=p->next;
         }
         insaft(p,67);

    }
    printf("after insertion\n");
   traverse(start);

    return 0;

}
