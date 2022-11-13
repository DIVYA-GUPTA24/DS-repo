#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

void traverse(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(ptr + i) << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    traverse(nums, n);
}
