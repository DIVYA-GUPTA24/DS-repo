#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[4];
    int *ptr=a;
    for(int i=0;i<=3;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<=3;i++)
    {
        cout<<*(ptr+i)<<" ";
    }
    cout<<"\n";
    for(int i=0;i<=3;i++)
    {
        cout<<*(a+i)<<" ";
    }

}
