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

void insend(struct node **start, char x)
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
void insaft(struct node *q, char x)
{
   struct node *r;
   struct node *p;
   r = q->next;
   p = getnode();
   p->info = x;
   p->next = r;
   q->next = p;
}
int delaft(struct node *p)
{
    struct node *q,*r;
    if(p==NULL|| p->next==NULL)
    {
        printf("void deletion");
        return -1;

    }
    q=p->next;
    char x=q->info;
    r=q->next;
    p->next=r;
    free(q);
    return x;

}
void arrange(struct node **start)
{
    struct node *p,*q;
    q=NULL;
    p=(*start);
    char x;
    while(p!=NULL)
    {
        if(p->info=='A'|| p->info=='E'|| p->info=='I' || p->info=='O'|| p->info=='U')
        {
            if(p->info==(*start)->info)
            {
                q=p;
                p=p->next;

            }
            else
           {
            insbeg(&(*start),p->info);
            p=p->next;
            delaft(q);
            }

        }
        else
            {
                q=p;
                p=p->next;

            }
        }
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



int main()
{
   struct node *start;
   char x;
   start = NULL;
   insbeg(&start, 'A');
   insbeg(&start, 'Y');
   insbeg(&start, 'V');
   insbeg(&start, 'I');
   insbeg(&start, 'D');
   printf("Linked List before arranging: ");
   traverse(&start);
   printf("Linked List after arranging: ");
   arrange(&start);
   traverse(&start);
   return 0;


}
