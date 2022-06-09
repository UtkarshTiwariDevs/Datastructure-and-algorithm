#include <bits/stdc++.h>
using namespace std;
int static t[1001][1001];

int solve(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (t[i][j] != -1)
    {
        return t[i][j];
    }

    int ansMin = INT_MAX;

    for (int k = i; k <= j - 1; k++)
    {
        int tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if (tempAns < ansMin)
        {
            ansMin = tempAns;
        }
    }
    return t[i][j] = ansMin;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    // assigning i and j
    int i = 1;
    int j = (sizeof(arr) / sizeof(arr[0])) - 1;
    memset(t, -1, sizeof(t));

    cout << solve(arr, i, j);
    return 0;
}