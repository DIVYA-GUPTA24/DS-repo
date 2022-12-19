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
    p=(*t);
    q=NULL;
    if((*t)==NULL)
    {
        (*t)=makenode(x);
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
    while((t)!=NULL)
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

struct node *minimum(struct node *t)
{
    while(t->left!=NULL)
    {
        t=t->left;
    }
    return t;
}

struct node *bstsuccessor(struct node *p)
{
    struct node *q;
    if(p->right!=NULL)
    {
        q=minimum(p->right);
    }
    else
    {
        q=p->father;
        while(q!=NULL && q->right==p)
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
    int key;
    printf("\nEnter Key: ");
    scanf("%d",&key);

    struct node *f,*s;
    f=bstsearch(root,key);
    printf("\nthe successor of %d : ",key);
    s=bstsuccessor(f);
    if(s!=NULL)
    {
        printf("%d",s->data);
    }
    else
    {
        printf("doesn't exist");
    }
}
