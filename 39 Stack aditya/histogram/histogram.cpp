#include <bits/stdc++.h>
using namespace std;

vector<int> nsl(int n, int a[])
{
    vector<int> left;
    stack<pair<int, int>> s;
    int pseudo = -1;

    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
            left.push_back(pseudo);
        else if (s.size() > 0 && a[i] > s.top().first)
            left.push_back(s.top().second);
        else if (s.size() > 0 && a[i] <= s.top().first)
        {
            while (s.size() > 0 && a[i] <= s.top().first)
                s.pop();
            if (s.size() == 0)
                left.push_back(pseudo);
            else
                left.push_back(s.top().second);
        }
        s.push({a[i], i});
    }
    // for(int i=0;i<left.size();i++)
    //     cout<<left[i]<<" ";
    return left;
}
vector<int> nsr(int n, int a[])
{
    vector<int> right;
    stack<pair<int, int>> s2;
    int pseudo = n;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s2.size() == 0)
            right.push_back(pseudo);
        else if (s2.size() > 0 && a[i] > s2.top().first)
            right.push_back(s2.top().second);
        else if (s2.size() > 0 && a[i] <= s2.top().first)
        {
            while (s2.size() > 0 && a[i] <= s2.top().first)
                s2.pop();
            if (s2.size() == 0)
                right.push_back(pseudo);
            else
                right.push_back(s2.top().second);
        }
        s2.push({a[i], i});
    }
    reverse(right.begin(), right.end());
    // for(int i=0;i<right.size();i++)
    //     cout<<right[i]<<" ";
    return right;
}
void maxAreaHisto(int n, int a[])
{
    vector<int> left = nsl(n, a);
    vector<int> right = nsr(n, a);
    vector<int> width;
    vector<int> area;
    int maxArea = INT_MIN;

    for(int i=0;i<n;i++)
        width.push_back(right[i] - left[i] -1);
    for(int i=0;i<n;i++)
        maxArea = max(maxArea,(a[i]*width[i]));
    cout<<maxArea;
    // for(int i=0;i<n;i++)
    //     cout<<width[i]<<" ";
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // int ans = maxAreaHisto(n, a);
    // cout<<ans;
    // nsr(n,a);.
    maxAreaHisto(n, a);
    return 0;
}