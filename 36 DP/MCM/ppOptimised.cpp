#include <bits/stdc++.h>
using namespace std;

int static t[1001][1001];

bool isPalindrome(string s, int i, int j)
{
    if (i == j)
    {
        return true;
    }
    if (i > j)
    {
        return true;
    }

    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(string s, int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if (isPalindrome(s, i, j) == true)
    {
        return 0;
    }
    if (t[i][j] != -1)
    {
        return t[i][j];
    }
    int mn = INT_MAX;
    int left, right;
    for (int k = i; k <= j - 1; k++)
    {
        if (t[i][k] != -1)
        {
            left = t[i][k];
        }
        else
        {
            left = solve(s, i, k);
            t[i][k] = left;
        }

        if (t[k + 1][j] != -1)
        {
            right = t[k + 1][j];
        }
        else
        {
            right = solve(s, k + 1, j);
            t[k + 1][j] = right;
        }
        int tempans = 1 + left + right;
        if (tempans < mn)
        {
            mn = tempans;
        }
    }
    return t[i][j] = mn;
}
int main()
{
    string s = "nitinn";
    memset(t, -1, sizeof(t));
    cout << solve(s, 0, s.length() - 1);
    return 0;
}