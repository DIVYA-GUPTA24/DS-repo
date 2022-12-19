#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node *left;
   struct node *right;
};

struct node *makenode(int x)
{
   struct node *p;
   p = (struct node*)malloc(sizeof(struct node));
   p->data=x;
   p->left=NULL;
   p->right=NULL;
   return p;
}
void inordertraversal (struct node *t)
{

    if(t!=NULL)
    {

        inordertraversal(t->left);
        printf("%d ",t->data);
        inordertraversal(t->right);
    }
}
int bstinsert(struct node **t,int x)
{
    struct node *p,*q;
    p=*t;
    q=NULL;
    if(*t==NULL)
    {
        *t=makenode(x);
    }
    else
    {
    while(p!=NULL)
    {
         q=p;
         if(x<p->data)
         {
             p=p->left;
         }
         else
         {
             p=p->right;
         }
    }
    if(x<q->data)
    {
        q->left=makenode(x);
    }
    else{
       q->right=makenode(x);
    }
    }
}

struct node *bstsearch(struct node **t,int x)
{
    while((*t)!=NULL)
    {
    if((*t)->data==x)
    {
        return t;
    }
    else if(x<(*t)->data)
    {
        (*t)=(*t)->left;
    }
    else
    {
        (*t)=(*t)->right;
    }
    }
    return NULL;
}

int main()
{
    struct node *root;
    root=NULL;
    bstinsert(&root,100);
    bstinsert(&root,200);
    bstinsert(&root,300);
    bstinsert(&root,400);
    bstinsert(&root,700);
    bstinsert(&root,900);
    bstinsert(&root,1000);
    bstinsert(&root,500);
    bstinsert(&root,600);
    bstinsert(&root,800);
    struct node *t;
    t=bstsearch(&root,600);
    if(t==NULL)
    {
        printf("element not found");
    }
    else
    {
        printf("element found");
    }
}
