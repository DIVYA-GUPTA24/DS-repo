#include <bits/stdc++.h>
using namespace std;
int main()
{
    char name[20];
    int t;
    int i=0;
    int j=i-1; 
    while(j<i)
    {
        t=name[i];
        name[i]=name[j];
        name[j]=t;
        j++;
        i--;
    }
    cout<<name;
}