#include <stdio.h>
#include <stdlib.h>
struct node
{

   int coef;
   int exp;
   struct node *next;
};

struct node *getnode()
{
   struct node *p;
   p = (struct node*)malloc(sizeof(struct node));
   return p;
}
void insbeg(struct node **start, int x,int y)
{
   struct node *p;
   p = getnode();
   p->coef = x;
   p->exp = y;
   p->next = (*start);
   (*start) = p;
}

void insend(struct node **start, int x, int y)
{
   struct node *q;
   q = (*start);
   if(q==NULL)
    {
    insbeg(&(*start),x,y);
   }
   else{
   while (q->next != NULL)
   {
      q = q->next;
   }
   struct node *p;
   p = getnode();
   p->coef = x;
   p->exp = y;
   p->next = NULL;
   q->next = p;
   }
}
void traverse(struct node *start)
{
   struct node *p;
   p = start;
   while (p != NULL)
   {
      printf("%d", p->coef);
      printf("x^");
      printf("%d", p->exp);

      printf(" + ");
      p = p->next;
   }
   printf("\n");
}
void insaft(struct node *q, int x,int y)
{
   struct node *r;
   struct node *p;
   r = q->next;
   p = getnode();
   p->coef = x;
   p->exp = y;
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
    int x=p->coef;
    int y=p->exp;
    free(p);
    return x;
    return y;

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
    int x=q->coef;
    r=q->next;
    p->next=r;
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
    int x=p->coef;
    int y=p->exp;
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
void polynomialaddition(struct node **poly1,struct node **poly2)
{
    struct node *p,*q;
    struct node *start=NULL;
    p=(*poly1);
    q=(*poly2);
    while(p!=NULL && q!=NULL)
    {
         if((p->exp)==(q->exp))
         {
              insend(&start,((p->coef)+(q->coef)),p->exp);
              p=p->next;
              q=q->next;
         }
          else if((p->exp)>(q->exp))
            {
              insend(&start,p->coef,p->exp);
              p=p->next;
            }
            else
            {
                  insend(&start,q->coef,q->exp);
                  q=q->next;

            }

    }
    while(p!=NULL)
    {
        insend(&start,p->coef,p->exp);
        p=p->next;

    }
    while(q!=NULL)
    {
        insend(&start,q->coef,q->exp);
        q=q->next;
    }
    traverse(start);
}



int main()
{
    struct node *poly1,*poly2;
   poly1 = NULL;
   printf("first polynomial: ");
   insbeg(&poly1, 2,1);
   insbeg(&poly1, 9,2);
   insbeg(&poly1, 8,3);
   insbeg(&poly1, 5,4);
   insbeg(&poly1, 6,5);
   traverse(poly1);
  
   poly2=NULL;
   printf("second polynomial: ");
   insbeg(&poly2, 3,1);
   insbeg(&poly2, 8,2);
   insbeg(&poly2, 5,3);
   insbeg(&poly2, 6,4);
   insbeg(&poly2, 7,5);
   traverse(poly2);

   printf("polynomial after addition: ");
   polynomialaddition(&poly1,&poly2);
   return 0;

}
