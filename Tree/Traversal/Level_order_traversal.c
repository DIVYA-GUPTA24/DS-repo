#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};

struct node *rear,*front;

struct node *makenode(int x)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->next=NULL;
    return p;
}

void initialize()
{
    rear=NULL;
    front=NULL;
}

int isempty()
{
    if (front==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(struct node *p)
{
    if(rear!=NULL)
    {
        rear->next=p;
        rear=p;
    }
    else{
        front=p;
        rear=front;
    }
}

struct node *dequeue()
{
    struct node *p;
    p=front;
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
    }
    else{
        front=front->next;
    }
    return p;
}

void levelordertraversal(struct node *root)
{
    initialize();
    struct node *p;
    p=root;
    enqueue(p);
    while(!isempty())
    {
        struct node *x=dequeue();
        printf("\t%d",x->data);
        if(x->left!=NULL)
        {
            enqueue(x->left);
        }
        if(x->right!=NULL)
        {
            enqueue(x->right);
        }

    }
}

void main()
{
    struct node *root;
    root=NULL;
    root=makenode(1);
    root->left=makenode(2);
    root->right=makenode(3);
    root->left->left=makenode(4);
    root->left->right=makenode(5);
    root->right->left=makenode(6);
    root->right->right=makenode(7);
    printf("level order traversal: ");
    levelordertraversal(root);
}
