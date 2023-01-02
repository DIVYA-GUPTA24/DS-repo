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

int Max_path_sum(Node *&t)
{
    if(t==NULL)
        return 0;
    else
    {
        if(t->left==NULL || t->right==NULL)
            return t->data;
        else
        {
            int L=Max_path_sum(t->left);
            int R=Max_path_sum(t->right);
            int M=max(L,R);
            return t->data+M;
        }
    }
}

int main()
{
    Node *root;
    root=NULL;
    root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(8);
    root->left->left=new Node(7);
    root->left->right=new Node(9);
    root->right->left=new Node(5);
    root->right->right=new Node(11);
    cout << "Maximal path sum of binary tree: ";
    int s=Max_path_sum(root);
    cout << s;
}
