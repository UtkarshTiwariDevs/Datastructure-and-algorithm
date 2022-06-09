#include <bits/stdc++.h>
using namespace std;
int lps(string x, int m)
{
    string y = x;
    reverse(y.begin(), y.end());
    int t[m + 1][m + 1];

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            t[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[m][m];
}
int main()
{
    string x;
    cin >> x;
    int m = x.length();
    cout << lps(x, m);
    return 0;
}