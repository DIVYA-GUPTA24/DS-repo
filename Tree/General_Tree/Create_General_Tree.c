#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node *child;
   struct node *sibling;
};

struct node *makenode(int x)
{
   struct node *p;
   p = (struct node*)malloc(sizeof(struct node));
   p->data=x;
   p->child=NULL;
   p->sibling=NULL;
   return p;
}

void CreateTree(struct node **t)
{
    struct node *p;
    int choice,x;
    printf("whether the child of %d exists?(1/0)",(*t)->data);
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("the data at child node",(*t)->child);
        scanf("%d",&x);
        p=makenode(x);
        (*t)->child=p;
        CreateTree(&p);
    }

    printf("whether the sibling of %d exists?(1/0)",(*t)->data);
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("the data at sibling node",(*t)->sibling);
        scanf("%d",&x);
        p=makenode(x);
        (*t)->sibling=p;
        CreateTree(&p);
    }

}

int preordertraversal(struct node *t)
{
    if(t!=NULL)
    {

        printf("%d ",t->data);
        preordertraversal(t->child);
        preordertraversal(t->sibling);
    }


}
void inordertraversal (struct node *t)
{

    if(t!=NULL)
    {

        inordertraversal(t->child);
        printf("%d ",t->data);
        inordertraversal(t->sibling);
    }
}
void postordertraversal(struct node *t)
{

    if(t!=NULL)
    {
        postordertraversal(t->child);
        postordertraversal(t->sibling);
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
