#include <bits/stdc++.h>
using namespace std;

void coinChange(int coin[], int n, int sum)
{
    int t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 0;
    }
    for (int j = 0; j < sum + 1; j++)
    {
        t[0][j] = INT_MAX - 1;
    }
    for (int j = 1; j < sum + 1; j++)
    {
        if (j % coin[0] == 0)
        {
            t[1][j] = (j / coin[0]);
        }
        else
        {
            t[1][j] = INT_MAX - 1;
        }
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                t[i][j] = min(t[i][j - coin[i - 1]] + 1, t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    cout << t[n][sum];
}
int main()
{
    int n, sum;
    cin >> n >> sum;
    int coin[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    coinChange(coin, n, sum);
    return 0;
}