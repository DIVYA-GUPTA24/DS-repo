#include<bits/stdc++.h>
using namespace std;

void DFSVisit(int i,vector<int>&visited,vector<int>&pred,vector<int>adj[])
{
    cout<<i<<" ";
    visited[i]=1;
    for(int j=0; j<adj[i].size(); j++)
    {
        if(visited[adj[i][j]]==0)
        {
            DFSVisit(adj[i][j],visited,pred,adj);
            pred[adj[i][j]]=i;
        }
    }
}

void DFS(vector<int>adj[],int n)
{
    vector<int>visited(n,0);
    vector<int>pred(n,-1);
    for(int i=0; i<n; i++)
    {
        if(visited[i]==0)
        {
            DFSVisit(i,visited,pred,adj);
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the no of vertices: ";
    cin>>n;
    int e,a,b;
    cout<<"Enter the no of edges: ";
    cin>>e;
    vector<int>adj[n];
    for(int i=1; i<=e; i++)
    {
        cout<<"Enter the end points: ";
        cin>>a>>b;
        adj[a].push_back(b);
    }

    for(int i=0; i<n; i++)
    {
        cout<<i<<":";
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
    DFS(adj,n);

}
