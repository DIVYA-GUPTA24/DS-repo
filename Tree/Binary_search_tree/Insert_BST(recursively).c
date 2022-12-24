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
    if(*t==NULL)
        *t=makenode(x);
    else
    {
       if(x<(*t)->data)
       {
           (*t)->left=bstinsert((*t)->left,x);
       }
       else
       {
           (*t)->right=bstinsert((*t)->right,x);
       }
    }
    printf("%d",(*t)->data);
}

int main()
{
    struct node *root;
    root=NULL;
    printf("the root node data after insertion in bst: ");
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
}
