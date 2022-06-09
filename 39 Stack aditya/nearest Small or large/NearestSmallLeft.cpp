#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int n = 5;

    vector<int> ans;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
            ans.push_back(-1);
        else if (s.size() > 0 && arr[i]>s.top())
            ans.push_back(s.top());
        else if (s.size() > 0 && arr[i]<=s.top())
        {
            while (s.size() > 0 && s.top() >= arr[i])
                s.pop();
            if (s.size() == 0)
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}

