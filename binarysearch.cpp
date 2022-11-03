#include <iostream>
using namespace std;
int binarysearch(int a[10],int low,int high, int key,int mid)
{
while(low<=high)
{
mid=(low+high)/2;
if(a[mid]==key)
return mid;
else
if(key<a[mid])
high=mid-1;
else
low=mid+1;}
return -1;
}

int main()
{
int a[10],low,high,key,mid,ans;
cin>>key;
for(int i=0;i<10;i++)
cin>>a[i];
low=0,high=9;
ans=binarysearch(a,low,high,key,mid);
cout<<ans;
}
