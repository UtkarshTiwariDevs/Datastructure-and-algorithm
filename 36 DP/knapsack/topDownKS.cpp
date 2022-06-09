#include <bits/stdc++.h>
using namespace std;

int topDown(int wt[], int val[], int n, int w)
{
    int t[n + 1][w + 1];

    // base condition
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    // choice diagram
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]],
                              t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][w];
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 10;
    int n = 4;
    cout << topDown(wt, val, n, w);
    return 0;
}
