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
    vector<vector<int>>IncidenceMatrix(v,vector<int>(e,0));
    int a,b;
    for(int i=1;i<=e;i++)
    {
        cout<<"Enter the end points: ";
        cin>>a>>b;
        IncidenceMatrix[a][i-1]=1;
        IncidenceMatrix[b][i-1]=1;
    }
    cout<<"IncidenceMatrix:"<<endl;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<e;j++)
        {
            cout<<IncidenceMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
