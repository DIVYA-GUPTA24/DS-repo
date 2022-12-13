#include <stdio.h>
#include <stdlib.h>

struct node
{
   char data;
   struct node *left;
   struct node *right;
};

struct node *makenode(char x)
{
   struct node *p;
   p = (struct node*)malloc(sizeof(struct node));
   p->data=x;
   p->left=NULL;
   p->right=NULL;
   return p;
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

void main()
{
    struct node *root;
    root=NULL;
    root=makenode('A');
    root->left=makenode('B');
    root->right=makenode('C');
    root->left->left=makenode('D');
    root->right->left=makenode('E');
    root->right->right=makenode('F');
    int h=height(root);
    printf("the height of the tree is %d",h);

}
