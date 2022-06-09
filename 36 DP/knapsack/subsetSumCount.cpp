#include <bits/stdc++.h>
using namespace std;

int subsetSumCount(int a[], int n, int sum)
{
    int t[n + 1][sum + 1];
    for (int j = 0; j < sum + 1; j++)
        t[0][j] = 0;
    for (int i = 0; i < n + 1; i++)
        t[i][0] = 1;

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
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}
int main()
{
    int a[] = {2, 3, 5, 6, 8, 10};
    int n = sizeof(a) / sizeof(a[0]); //  (24/4) = 6
    int sum = 10;
    cout << subsetSumCount(a, n, sum);
    return 0;
}