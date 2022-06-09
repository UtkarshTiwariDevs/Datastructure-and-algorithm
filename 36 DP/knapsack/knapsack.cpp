#include <bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }

    if (wt[n - 1] <= w)
    {
        return max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1),
                   knapsack(wt, val, w, n - 1));
    }
    else
    {
        return knapsack(wt, val, w, n - 1);
    }
}
int main()
{
    int wt[] = {1, 3, 4, 5,4,8,10,19};
    int val[] = {1, 4, 5, 7,15,35,12,6};
    int w = 25;
    int n = 8;

    cout << knapsack(wt, val, w, n);
    return 0;
}