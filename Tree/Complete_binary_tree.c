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
int max(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

int height(struct node *t)
{
    if(t==NULL)
        return 0;
    else if(t->left==NULL && t->right==NULL)
        return 0;
    else
        return max(height(t->left),height(t->right))+1;
}

void complete_binary_tree(struct node *t)
{
    if(countN1(t)==0 && (height(t->left)==height(t->right)))
        printf("A complete binary tree");
    else
        printf("Not a complete binary tree");
}

void main()
{
    struct node *root;
    root=NULL;
    root=makenode(100);
    root->left=makenode(200);
    root->right=makenode(300);
    root->left->left=makenode(400);
    root->left->right=makenode(700);
    root->right->left=makenode(500);
    root->right->right=makenode(600);
    complete_binary_tree(root);

}
