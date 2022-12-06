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
void traverse(struct node *top)
{
   struct node *p;
   p = top;
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

int push(struct node **top,int x)
{
    insbeg(&(*top),x);
}

int pop(struct node **top)
{
    int x=delbeg(&(*top));
    return x;
}



int main()
{
   struct node *top;
   top = NULL;
   push(&top, 200);
   push(&top, 300);
   push(&top, 400);
   push(&top, 500);
   push(&top, 600);
   traverse(top);

   int x;
   x=pop(&top);
   printf("deleted element is %d",x);

   x=pop(&top);
   printf("\ndeleted element is %d",x);

   return 0;

}
