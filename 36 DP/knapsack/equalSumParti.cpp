#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int set[], int n, int sum)
{
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];
}

bool solve(int set[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        sum += set[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    else
    {
        return isSubsetSum(set, n, (sum / 2));
    }
}

int main()
{
    int set[] = {1, 5, 11, 5};

    int n = sizeof(set) / sizeof(set[0]);
    int sum = 0;
    if (solve(set, n, sum) == true)
        cout << "Equal partition possible";
    else
        cout << "No equal partition possible";
    return 0;
}