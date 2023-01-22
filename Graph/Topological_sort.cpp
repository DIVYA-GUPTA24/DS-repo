#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int V,E;
    cout<<"How many vertices are there?";
    cin>>V;
    cout<<"How many edges are there?";
    cin>>E;

    vector<int>adjlist[V];
    vector<int>DAT(V,0);

    for(int i=1;i<=E;i++)
    {
        int a,b;
        cout<<"Enter the end points: ";
        cin>>a>>b;
        adjlist[a].push_back(b);
        DAT[b]++;
    }
    for(int i=0;i<V;i++)
    {
        cout<<i<<": ";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Outdegrees are: "<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<i<<": ";
        cout<<adjlist[i].size()<<endl;
    }
    cout<<"Indegrees are: "<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<i<<": ";
        cout<<DAT[i]<<endl;
    }
    queue<int>Q;
    for(int i=0;i<V;i++)
    {
        if(DAT[i]==0)
            Q.push(i);
    }
    cout<<endl<<"Topological sort sequence is: ";
    while(Q.size()!=0)
    {
        int x=Q.front();
        Q.pop();
        for(int j=0;j<adjlist[x].size();j++)
        {
            DAT[adjlist[x][j]]--;
            if(DAT[adjlist[x][j]]==0)
                Q.push(adjlist[x][j]);
        }
        cout<<x<<" ";
    }

}
