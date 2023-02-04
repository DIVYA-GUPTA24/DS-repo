#include<iostream>
#include<stdlib.h>
#include<vector>
#include <queue>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int level;
    int hd;
};

struct node *makenode(int x)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void CreateTree(struct node **t)
{
    struct node *p;
    int choice,x;
    cout<<"whether the left of "<<(*t)->data<<"exists?(1/0)";
    cin>>choice;
    if(choice==1)
    {
        cout<<"Input the data of left of "<<(*t)->data;
        cin>>x;
        p=makenode(x);
        (*t)->left=p;
        CreateTree(&p);
    }

    cout<<"whether the right of "<<(*t)->data<<"exists?(1/0)";
    cin>>choice;
    if(choice==1)
    {
        cout<<"Input the data of right of "<<(*t)->data;
        cin>>x;
        p=makenode(x);
        (*t)->right=p;
        CreateTree(&p);
    }

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

void Top_bottom_view_traversal(struct node *t)
{
    queue<struct node *>Q;
    int h=height(t);
    vector<int>HT[2*h+1];
    Q.push(t);
    t->hd=0;
    HT[t->hd+h].push_back(t->data);
    while(Q.size()!=0)
    {
        struct node *x;
        x=Q.front();
        Q.pop();
        if(x->left!=NULL)
        {
            x->left->hd=x->hd-1;
            Q.push(x->left);
            HT[x->left->hd+h].push_back(x->left->data);
        }
        if(x->right!=NULL)
        {
            x->right->hd=x->hd+1;
            Q.push(x->right);
            HT[x->right->hd+h].push_back(x->right->data);

        }
    }
     cout<<endl<<"Top view of the Tree is: ";
    for(int i=0;i<2*h+1;i++)
    {
        if(HT[i].size()!=0)
        cout<<HT[i][0]<<" ";

    }
    cout<<endl<<"Bottom view of the Tree is: ";
    for(int i=0;i<2*h+1;i++)
    {
        int x=HT[i].size();
        if(HT[i].size()!=0)
        cout<<HT[i][x-1]<<" ";

    }
}

int main()
{
    struct node *root;
    root=NULL;
    int x;
    cout<<"Enter the data of root node";
    scanf("%d",&x);
    root=makenode(x);

    CreateTree(&root);
    Top_bottom_view_traversal(root);
    return 0;
}
