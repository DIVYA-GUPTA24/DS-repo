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

int minimum(struct node *t)
{
    while(t->left!=NULL)
    {
        t=t->left;
    }
    printf("%d", t->data);
}

int maximum(struct node *t)
{
    while(t->right!=NULL)
    {
        t=t->right;
    }
    printf("%d", t->data);
}

int main()
{
    struct node *root;
    root=NULL;
    bstinsert(&root,100);
    bstinsert(&root,50);
    bstinsert(&root,150);
    bstinsert(&root,20);
    bstinsert(&root,70);
    bstinsert(&root,120);
    bstinsert(&root,200);
    bstinsert(&root,30);
    bstinsert(&root,105);
    bstinsert(&root,170);
    bstinsert(&root,290);
    bstinsert(&root,180);
    printf("binary tree after insertion: ");
    inordertraversal(root);
    printf("\nminimum: ");
    minimum(root);
    printf("\nmaximum: ");
    maximum(root);
}
