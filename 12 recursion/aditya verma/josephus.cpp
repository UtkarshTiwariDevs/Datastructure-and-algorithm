#include <bits/stdc++.h>
using namespace std;

void josephus(vector<int> v, int k, int index, int &ans)
{
    if (v.size() == 1)
    {
        ans = v[0];
        return;
    }
    index = (index + k) % v.size();
    v.erase(v.begin() + index);
    josephus(v, k, index, ans);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }

    k = k - 1;
    int ans = -1;
    int index = 0;

    josephus(v, k, index, ans);
    cout << ans;
    return 0;
}