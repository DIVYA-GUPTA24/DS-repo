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
void insbeg(struct node **start, char x)
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
      printf("%c ", p->info);
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
char delbeg(struct node **start)
{
    if(start==NULL)
    {
        printf("void deletion");
        exit(1);
    }
    struct node *p;
    p=*start;
    *start=(*start)->next;
    char x=p->info;
    free(p);
    return x;

}
char delaft(struct node **p)
{
    struct node *q,*r;
    if((*p)==NULL|| (*p)->next==NULL)
    {
        printf("void deletion");
        return -1;

    }
    q=(*p)->next;
    char x=q->info;
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

void deletealloccurences(struct node **start,char x)
{
    struct node *p,*q;
    p=(*start);
    q=NULL;

    while(p!=NULL)
    {
        if(p->info=='x')
        {
            if(q==NULL)
            {
                p=p->next;
                delbeg(&(*start));
            }
            else
                {
                    p=p->next;
                    delaft(&q);
                }
        }
        else
            {
                q=p;
                p=p->next;
            }
    }
    traverse(&(*start));

}

int main()
{
   struct node *start;
   start = NULL;
   char x;
   insbeg(&start, 'x');
   insbeg(&start, 'D');
   insbeg(&start, 'x');
   insbeg(&start, 'x');
   insbeg(&start, 'C');
   insbeg(&start, 'x');
   insbeg(&start, 'B');
   insbeg(&start, 'A');
   insbeg(&start, 'x');
   insbeg(&start, 'x');
   printf("linked list before deleting all x: ");
   traverse(&start);
   printf("linked list after deleting all x: ");
   deletealloccurences(&start,x);

}

