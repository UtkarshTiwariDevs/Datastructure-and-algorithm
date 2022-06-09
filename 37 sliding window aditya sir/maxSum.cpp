/*
Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

Example:

Input:
N = 4, K = 2
Arr = [100, 200, 300, 400]
Output:
700
Explanation:
Arr3  + Arr4 =700,
which is maximum.
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int a[], int n, int k)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int mxSum = INT_MIN;
    while (j < n)
    {
        sum += a[j];
        if ((j - i + 1) < k)
        {
            j++;
        }
        else if ((j - i + 1) == k)
        {
            mxSum = max(mxSum, sum);
            sum = sum - a[i];
            i++;
            j++;
        }
    }
    return mxSum;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout<<solve(a,n,k);
    return 0;
}