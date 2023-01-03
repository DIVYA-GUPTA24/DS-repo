#include<iostream>
#include<vector>
using namespace std;

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
    for(int i=0;i<V;i++)
    {
        cout<<i<<": ";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }

}

