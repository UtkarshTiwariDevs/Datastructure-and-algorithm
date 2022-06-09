#include <bits/stdc++.h>
using namespace std;

void subsetSum(int a[], int range, int n)
{
    int t[n + 1][range + 1];
    for (int j = 0; j < range + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < range + 1; j++)
        {
            if (a[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j] || t[i - 1][j - a[i - 1]];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    vector<int> v;
    for (int j = 0; j < (range + 1) / 2; j++)
    {
        if (t[n][j] == 1)
        {
            v.push_back(j);
        }
    }
    int mn = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        mn = min(mn, (range - 2*(v[i])));
    }
    cout << mn;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    int range = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        range += a[i];
    }
    subsetSum(a, range, n);
    return 0;
}