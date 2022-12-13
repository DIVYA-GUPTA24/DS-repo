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

int countN1(struct node *t)
{
    if(t==NULL)
        return 0;
    else if(t->left==NULL && t->right==NULL)
        return 0;
    else if(t->left!=NULL && t->right!=NULL)
        return countN1(t->left)+countN1(t->right);
    else
        return 1+countN1(t->left)+countN1(t->right);
}

int strictly_binary_tree(struct node *t)
{
   int x=countN1(t);
   if(x==0)
    printf("strictly binary tree");
   else
    printf("not a strictly binary tree");

}

void main()
{
    struct node *root;
    root=NULL;
    root=makenode(100);
    root->left=makenode(200);
    root->right=makenode(300);
    root->right->left=makenode(500);
    root->right->right=makenode(600);
    strictly_binary_tree(root);

}
