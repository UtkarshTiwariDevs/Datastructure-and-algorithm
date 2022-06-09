#include <bits/stdc++.h>
using namespace std;

int rwt(int n, int a[])
{
    int maxl[n];
    maxl[0] = a[0];
    for (int i = 1; i < n; i++)
        maxl[i] = max(maxl[i - 1], a[i]);

    int maxr[n];
    maxr[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        maxr[i] = max(maxr[i + 1], a[i]);
    
    int water[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
        water[i] = min(maxl[i], maxr[i]) - a[i];
    for(int i=0;i<n;i++)
        sum+=water[i];
    return sum;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = rwt(n, a);
    cout << ans;
    return 0;
}