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

void Zig_zag_traversal(struct node *root)
{
    queue<struct node *>Q;
    int h=height(root);
    Q.push(root);
    root->level=0;
    vector<int>HT[h+1];
    HT[root->level].push_back(root->data);
    cout<<"Zig Zag traversal of the tree is: ";
    while(Q.size()!=0)
    {
        struct node *x;
        x=Q.front();
        Q.pop();
        if(x->left!=NULL)
        {
            x->left->level=x->level+1;
            Q.push(x->left);
            HT[x->left->level].push_back(x->left->data);
        }
        if(x->right!=NULL)
        {
            x->right->level=x->level+1;
            Q.push(x->right);
            HT[x->right->level].push_back(x->right->data);
        }
    }
    int flag=1;

    for(int i=0; i<=h; i++)
    {
        if(flag%2!=0)
        {

            for(int j=0; j<HT[i].size(); j++)
            {
                cout<<HT[i][j]<<" ";
            }

        }
        else
        {
            int x=HT[i].size();
            for(int j=x-1; j>=0; j--)
            {
                cout<<HT[i][j]<<" ";
            }

        }
        flag++;
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
    Zig_zag_traversal(root);
    return 0;
}
