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
    if(t!=NULL)
    {
        printf("%c ",t->data);
        preordertraversal(t->left);
        preordertraversal(t->right);
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
}
