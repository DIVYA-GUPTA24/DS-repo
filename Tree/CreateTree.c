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

void CreateTree(struct node **t)
{
    struct node *p;
    int choice,x;
    printf("whether the left of %d exists?(1/0)",(*t)->data);
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("the data at left node",(*t)->left);
        scanf("%d",&x);
        p=makenode(x);
        (*t)->left=p;
        CreateTree(&p);
    }

    printf("whether the right of %d exists?(1/0)",(*t)->data);
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("the data at right node",(*t)->right);
        scanf("%d",&x);
        p=makenode(x);
        (*t)->right=p;
        CreateTree(&p);
    }

}

int preordertraversal(struct node *t)
{
    if(t!=NULL)
    {

        printf("%d ",t->data);
        preordertraversal(t->left);
        preordertraversal(t->right);
    }


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
void postordertraversal(struct node *t)
{

    if(t!=NULL)
    {
        postordertraversal(t->left);
        postordertraversal(t->right);
        printf("%d ",t->data);

    }
}


int main()
{

    struct node *root;
    root=NULL;
    int x;
    printf("enter the data of root node: ");
    scanf("%d",&x);
    root=makenode(x);
    CreateTree(&root);
    printf("preorder traversal is: ");
    preordertraversal(root);
    printf("\n");
    printf("inorder traversal is: ");
    inordertraversal(root);
    printf("\n");
    printf("postorder traversal is: ");
    postordertraversal(root);
}

