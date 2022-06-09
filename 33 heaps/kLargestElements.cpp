#include <bits/stdc++.h>
using namespace std;

void kLargestElements(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < n; i++)
    {
        minH.push(arr[i]);
        if (minH.size() > k)
        {
            minH.pop();
        }
    }

    while (minH.size() > 0)
    {
        cout<<minH.top()<<" ";
        minH.pop();
    }
}
int main()
{
    int n, k;
    // cout<<"Enter no. of elements and k resp"<<endl;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    kLargestElements(arr,n,k);
    return 0;
}