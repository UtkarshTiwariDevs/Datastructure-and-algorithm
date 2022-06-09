#include <bits/stdc++.h>
using namespace std;

// return count of the subsets with a given difference
// s1 - s2 = given number
void solve(int a[], int n, int diff)
{
    int sum = 0, sumArr = 0;
    for (int i = 0; i < n; i++)
    {
        sumArr += a[i];
    }
    sum = (diff + sumArr) / 2;

    int t[n + 1][sum + 1];

    for (int j = 0; j < sum + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (a[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j] + t[i - 1][j - a[i - 1]];
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    cout<<t[n][sum];
}
int main()
{
    int n, diff;
    cin >> n >> diff;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    solve(a, n, diff);
    return 0;
}