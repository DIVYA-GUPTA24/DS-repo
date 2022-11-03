#include <bits/stdc++.h>
using namespace std;
void traverse(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout<<"Array elements are:  ";
   traverse(A,n);
}
