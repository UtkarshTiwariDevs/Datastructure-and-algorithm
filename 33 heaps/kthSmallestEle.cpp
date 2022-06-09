#include <bits/stdc++.h>
using namespace std;

int kSmallestElement(int arr[], int n, int k)
{
    priority_queue<int> maxH;
    for (int i = 0; i < n; i++)
    {
        maxH.push(arr[i]);
        if (maxH.size() > k)
        {
            maxH.pop();
        }
    }
    return maxH.top();
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

    cout << kSmallestElement(arr, n, k);
    return 0;
}