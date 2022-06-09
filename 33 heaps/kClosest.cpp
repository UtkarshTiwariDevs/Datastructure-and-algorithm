#include <bits/stdc++.h>
using namespace std;

void kClosest(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int>> maxH;

    for (int i = 0; i < n; i++)
    {
        maxH.push({abs(arr[i] - x), arr[i]});

        if (maxH.size() > k)
        {
            maxH.pop();
        }
    }
    while (maxH.size() > 0)
    {
        cout << maxH.top().second << " ";
        maxH.pop();
    }
}
int main()
{
    int n, k, x;
    // cout<<"Enter no. of elements and k resp"<<endl;
    cin >> n >> k >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    kClosest(arr, n, k, x);
    return 0;
}