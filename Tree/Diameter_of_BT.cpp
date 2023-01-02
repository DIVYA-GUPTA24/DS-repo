#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void inordertraversal (Node *&t)
{

    if(t!=NULL)
    {
        inordertraversal(t->left);
        cout<<t->data;
        inordertraversal(t->right);
    }
}

int height(Node *&t)
{
    if(t==NULL)
        return 0;
    else if(t->left==NULL && t->right==NULL)
        return 1;
    else
        return max(height(t->left),height(t->right))+1;
}


int diameter(Node *&t)
{
    int d1,d2,d3,m;
    if(t==NULL)
        return 0;
    else
    {
        d1=height(t->left)+height(t->right)+1;
        d2=diameter(t->left);
        d3=diameter(t->right);
        m=max({d1,d2,d3});
        return m;
    }
}

int main()
{
    Node *root;
    root=NULL;
    root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->left->right=new Node(7);
    cout << "diameter of binary tree: ";
    int s=diameter(root);
    cout << s;
}
