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

int sum_of_all_nodes(struct node *t)
{
    if(t==NULL)
        return 0;
    else if(t->left==NULL && t->right==NULL)
        return t->data;
    else
        return t->data+sum_of_all_nodes(t->left)+sum_of_all_nodes(t->right);
}

void main()
{
    struct node *root;
    root=NULL;
    root=makenode(100);
    root->left=makenode(200);
    root->right=makenode(300);
    root->left->left=makenode(400);
    root->right->left=makenode(500);
    root->right->right=makenode(600);
    int s=sum_of_all_nodes(root);
    printf("sum of all nodes of the tree is %d",s);

}
