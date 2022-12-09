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
   p->next = *start;
   *start = p;
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
void copy_of_linkedlist(struct node **start1,struct node **start2)
{
    struct node *p;
    p=(*start1);
    while(p!=NULL)
    {
        insend(&(*start2),p->info);
        p=p->next;
    }
}

int main()
{
    struct node *start1, *start2;
    start1 = NULL;
    start2 = NULL;
    insend(&start1, 100);
    insend(&start1, 200);
    insend(&start1, 300);
    insend(&start1, 400);
    insend(&start1, 500);
    insend(&start1, 600);
    insend(&start1, 700);
    insend(&start1, 800);
    printf("Linked list 1: ");
    traverse(start1);

    printf("Copy of Linked List 1 in Linked List 2: ");
    copy_of_linkedlist(&start1, &start2);
    traverse(start2);

    return 0;

}
