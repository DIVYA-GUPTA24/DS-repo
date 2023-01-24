#include<iostream>
#include<vector>
#include<queue>
using namespace std;

BFS(vector<int>adjlist[],int V)
{
    vector<int>pred(V,-1);
    vector<int>visited(V);
    vector<int>dist(V);
    queue<int>Q;
    Q.push(0);
    visited[0]=1;
    cout<<"BFS: ";
    while(!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for(int j=0;j<adjlist[x].size();j++)
        {
            if(visited[adjlist[x][j]]==0)
            {
                Q.push(adjlist[x][j]);
                pred[adjlist[x][j]]=x;
                dist[adjlist[x][j]]=dist[x]+1;
                visited[adjlist[x][j]]=1;
            }

        }
        cout<<x<<" ";
    }
    cout<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<dist[i]<<" "<<pred[i];
        cout<<endl;
    }
}

int main()
{
    int V,E;
    cout<<"How many vertices are there?";
    cin>>V;
    cout<<"How many edges are there?";
    cin>>E;

    vector<int>adjlist[V];

    for(int i=1;i<=E;i++)
    {
        int a,b;
        cout<<"Enter the end points: ";
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    BFS(adjlist,V);
}
