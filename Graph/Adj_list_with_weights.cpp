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

    vector<pair<int,int>>adjlist[V+1];

    for(int i=1;i<=E;i++)
    {
        int a,b,w;
        cout<<"Enter the end points: ";
        cin>>a>>b>>w;
        adjlist[a].push_back({b,w});
        adjlist[b].push_back({a,w});
    }
    for(int i=0;i<V;i++)
    {
        cout<<i<<": ";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j].first<<" "<<adjlist[i][j].second<<" ";
        }
        cout<<endl;
    }

}
