#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *father;
};

struct node *makenode(int x)
{
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->father=NULL;
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
    struct node *p,*q;
    p=*t;
    q=NULL;
    if(*t==NULL)
    {
        *t=makenode(x);
    }
    else
    {
        while(p!=NULL)
        {
            q=p;
            if(x<p->data)
            {
                p=p->left;
            }
            else
            {
                p=p->right;
            }
        }
        if(x<q->data)
        {
            q->left=makenode(x);
            q->left->father=q;
        }
        else
        {
            q->right=makenode(x);
            q->right->father=q;
        }
    }
}

struct node *bstsearch(struct node *t,int x)
{
    while(t!=NULL)
    {
        if(t->data==x)
        {
            return t;
        }
        else if(x<t->data)
        {
            t=t->left;
        }
        else
        {
            t=t->right;
        }
    }
    return NULL;
}

struct node *maximum(struct node *t)
{
    while(t->right!=NULL)
    {
        t=t->right;
    }
    return t;
}

struct node *bstpredecessor(struct node *p)
{
    struct node *q;
    if(p->left!=NULL)
    {
        q=maximum(p->left);
    }
    else
    {
        q=p->father;
        while(q!=NULL && q->left==p)
        {
            p=q;
            q=q->father;
        }
    }
    return q;
}

int main()
{
    struct node *root;
    root=NULL;
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
    inordertraversal(root);
    struct node *f,*s;
    int key;
    printf("\nEnter key: ");
    scanf("%d",&key);
    f=bstsearch(root,key);
    printf("the predecessor of %d: ",key);
    s=bstpredecessor(f);
    if(s!=NULL)
    {
        printf("%d",s->data);
    }
    else
    {
        printf("doesn't exist");
    }
}
