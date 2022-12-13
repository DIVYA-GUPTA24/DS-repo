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

int preordertraversal(struct node *t)
{
    int count=0;
     while(t!=NULL)
     {
         count++;
    if(t!=NULL)
    {

        printf("%c ",t->data);
        preordertraversal(t->left);
        preordertraversal(t->right);
    }
    return count;
    }
}

void inordertraversal (struct node *t)
{

    if(t!=NULL)
    {

        inordertraversal(t->left);
        printf("%c ",t->data);
        inordertraversal(t->right);
    }
}

void postordertraversal(struct node *t)
{

    if(t!=NULL)
    {
        postordertraversal(t->left);
        postordertraversal(t->right);
        printf("%c ",t->data);
    }
}

int countLeafNodes(struct node *t)
{
    if(t==NULL)
        return 0;
    else if(t->left==NULL && t->right==NULL)
        return 1;
    else
        return countLeafNodes(t->left)+countLeafNodes(t->right);
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
    printf("preorder traversal is: ");
    preordertraversal(root);
    printf("\n");
    printf("inorder traversal is: ");
    inordertraversal(root);
    printf("\n");
    printf("postorder traversal is: ");
    postordertraversal(root);
    countLeafNodes(root);
}
