#include <bits/stdc++.h>
using namespace std;

int connectRopes(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> minH;
    for (int i = 0; i < n; i++)
    {
        minH.push(arr[i]);
    }
    int sum = 0;
    while (minH.size() >= 2)
    {
        int first = minH.top();
        minH.pop();
        int second = minH.top();
        minH.pop();

        int curr = first + second;
        sum = sum + curr;

        minH.push(curr);
    }
    return sum;
}

int main()
{
    int n;
    // cout<<"Enter no. of elements and k resp"<<endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << connectRopes(arr, n);
    return 0;
}