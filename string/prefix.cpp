#include<bits/stdc++.h>
using namespace std;
void prefix(string s1)
{
    int l=s1.length();
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<s1[j];
        }
        cout<<endl;
    }
}
int main()
{
    string s1;
    cin>>s1;
    prefix(s1);
}