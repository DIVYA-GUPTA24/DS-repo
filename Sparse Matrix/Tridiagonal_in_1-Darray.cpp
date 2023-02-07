#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[10][10],c[10];
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
        int l=(2*i+j-2);
        c[l]=a[i][j];
        cout<<c[l]<<" ";
        }
    }
}
