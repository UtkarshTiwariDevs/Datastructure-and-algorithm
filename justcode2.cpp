#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // for(int i=0;i<n;i++)
    //     cout<<a[i]<<" ";
    cout << endl;
    int x = (n*(n+1))/2;

    vector<int> sub[x];

    int m = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                sub[m].push_back(a[k]);
            }
            m++;
        }
    }

    // for (auto it : sub)
    // {
    //     for (auto it2 : it)
    //     {
    //         cout << it2 << ",";
    //     }
    //     cout << endl;
    // }
    // cout<<endl;

    int count = 0;

    for (auto it : sub)
    {
        int sum = 0;
        for (auto it2 : it)
        {
            sum += it2;
        }
        cout<<sum<<endl;
    }

    // for (auto it : sub)
    // {
    //     int sum = 0;
    //     for (auto it2 : it)
    //     {
    //         sum += it2;
    //     }
    //     if(sum == 0)
    //         count++;
    // }
    // cout<<count;
    return 0;
}