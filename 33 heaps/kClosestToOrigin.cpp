#include <bits/stdc++.h>
using namespace std;

void frequencySort(int arr[][2], int n, int k)
{
    priority_queue<pair<int, pair<int, int>>> maxH;
    for (int i = 0; i < n; i++)
    {
        maxH.push({arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1], {arr[i][0], arr[i][1]}});

        if (maxH.size() > k)
        {
            maxH.pop();
        }
    }

    while (maxH.size() > 0)
    {
        cout << maxH.top().second.first << " " << maxH.top().second.second << endl;
        maxH.pop();
    }
}
int main()
{
    int n,k;
    // cout<<"Enter no. of elements and k resp"<<endl;
    cin >> n>>k;
    int arr[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    frequencySort(arr,n,k);
    return 0;
}