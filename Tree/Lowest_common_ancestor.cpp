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

Node* LCA(Node *&t,int x,int y)
{
    Node *L,*R;
    int d1,d2,d3,m;
    if(t==NULL)
        return NULL;
    else
    {
        if(t->data==x || t->data==y)
            return t;
        else
            L=LCA(t->left,x,y);
            R=LCA(t->right,x,y);
            if(L==NULL)
                return R;
            else if(R==NULL)
                return L;
            else
                return t;
    }
}

int main()
{
    Node *root;
    root=NULL;
    root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(7);
    root->left->left->right=new Node(8);
    root->left->left->right->left=new Node(12);
    root->left->right=new Node(9);
    root->left->right=new Node(10);
    int x,y;
    cin >> x >> y;
    cout << "lowest common ancestor of binary tree: ";
    Node* s=LCA(root,x,y);
    cout << s->data;
}
