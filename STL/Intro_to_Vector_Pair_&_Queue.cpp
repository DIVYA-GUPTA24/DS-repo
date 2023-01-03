#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    vector<int>v;
    cout<<endl<<"memory allocated is: "<<v.capacity();

    v.push_back(1);
    cout<<endl<<"memory allocated is: "<<v.capacity();
    v.push_back(2);
    cout<<endl<<"memory allocated is: "<<v.capacity();
    v.push_back(3);
    cout<<endl<<"memory allocated is: "<<v.capacity();
    v.push_back(4);
    v.push_back(5);
    cout<<endl<<"memory allocated is: "<<v.capacity();
    v.push_back(6);
    cout<<endl<<"no of elements: "<<v.size();
    for(auto i:v)
        cout<<endl<<i;
    v.pop_back();
    cout<<endl;
    for(int i=0;i<v.size();i++)
          cout<<endl<<v[i];

    vector<pair<int,int>>a;
    a.push_back(make_pair(1234,98));
    a.push_back(make_pair(2345,96));
    a.push_back(make_pair(3456,88));
    a.push_back(make_pair(4567,91));


   cout<<endl<<"capacity is "<<a.capacity();
   cout<<endl<<"size is "<<a.size();
   for(int i=0;i<a.size();i++)
   {
        cout<<endl<<a[i].first;
        cout<<","<<a[i].second<<endl;
   }

   queue<int>q;
   q.push(1);
   q.push(2);
   q.push(3);
   q.push(4);
   q.push(5);
   cout<<endl<<q.empty(); //if empty,then 1,if not empty then 0
   cout<<endl<<q.front(); //show first element
   q.pop();
   cout<<endl<<q.front();
   q.pop();
   cout<<endl<<q.front();

}
