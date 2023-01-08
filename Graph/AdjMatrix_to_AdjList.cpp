#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int v,e;
    cout<<"How many vertices are there?";
    cin>>v;
    cout<<"How many edges are there?";
    cin>>e;
    vector<int>AdjList[v];
    vector<vector<int>>AdjMatrix(v,vector<int>(v,0));
    int a,b;
    for(int i=1;i<=e;i++)
    {
        cout<<"Enter the end points: ";
        cin>>a>>b;
        AdjMatrix[a][b]=1;
        AdjMatrix[b][a]=1;
    }
    cout<<"AdjMatrix:"<<endl;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
           cout<<AdjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<":"<<" ";
        for(int j=0;j<v;j++)
        {
            if(AdjMatrix[i][j]==1)
            {
                cout<<j<<",";
            }
        }
        cout<<endl;
    }

    return 0;
}
