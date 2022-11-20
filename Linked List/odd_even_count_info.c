#include <stdio.h>
#include <stdlib.h>
struct node
{
   int info;
   struct node *next;
};
struct node *start;
struct node *getnode()
{
   struct node *p;
   p = (struct node *)malloc(sizeof(struct node));
   return p;
}
void insbeg(int x)
{
   struct node *p;
   p = getnode();
   p->info = x;
   p->next = start;
   start = p;
}
void countingnodes()
{
    struct node *p;
    p=start;
    int c1=0,c2=0;
    while(p!=NULL)
    {
        printf("%d ", p->info);
        if(p->info%2==0)
        {

            p=p->next;
            c1++;
        }
        else
            {

            p=p->next;
            c2++;

            }
    }
    printf("\n%d", c1);
    printf("\n%d", c2);
}



void insend(int x)
{
   struct node *q, *p;
   q = start;
   while (q->next != NULL)
   {
      q = q->next;
   }
   p = getnode();
   p->info = x;
   p->next = NULL;
   q->next = p;
}

int main()
{
   start = NULL;
   insbeg(100);
   insbeg(225);
   insbeg(300);
   insbeg(455);
   insbeg(500);
   insbeg(600);
   insend(9);
   insend(20);
   insend(89);
   countingnodes();

}
