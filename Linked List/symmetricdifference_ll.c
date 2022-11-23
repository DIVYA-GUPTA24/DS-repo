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
   struct node *q;
   q = (*start);
   if(q==NULL)
   {
       insbeg(&(*start),x);
   }
   else{
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
void orderedinsertion(struct node **start,int x)
{
   struct node *p,*q;
   p=(*start);
   q=NULL;
   while((p!=NULL) && (x>=(p->info)))
   {
       q=p;
       p=p->next;
   }
   if(q==NULL)
   {
       insbeg(&(*start),x);

   }
   else
   {

       insaft(q,x);
   }


}
void symmetricdifferencell(struct node *start1,struct node *start2)
{
    struct node *p,*q,*start;
    p=start1;
    q=start2;
    start=NULL;
    while(p!=NULL && q!=NULL)
    {
          if((p->info)<(q->info))
        {
            insend(&start,p->info);
            p=p->next;

        }
        else if((p->info)>(q->info))
        {
            insend(&start,q->info);
            q=q->next;
        }
        else
            {

                p=p->next;
                q=q->next;

        }

    }
     while(p!=NULL)
    {
        insend(&start,p->info);
        p=p->next;
    }

     while(q!=NULL)
    {
        insend((&start),q->info);
        q=q->next;
    }


       traverse(start);

}

int main()
{
   struct node *start1,*start2;
   start1 = NULL;
   orderedinsertion(&start1,10);
   orderedinsertion(&start1,5);
   orderedinsertion(&start1,15);
   orderedinsertion(&start1,18);
   orderedinsertion(&start1,25);
   orderedinsertion(&start1,22);
   printf("first linked list: ");
   traverse(start1);
   start2=NULL;
   orderedinsertion(&start2,9);
   orderedinsertion(&start2,20);
   orderedinsertion(&start2,12);
   orderedinsertion(&start2,18);
   orderedinsertion(&start2,15);
   orderedinsertion(&start2,7);
   printf("\nsecond linked list: ");
   traverse(start2);

   printf("\nafter symmetric difference linked list: ");
   symmetricdifferencell(start1,start2);


}



