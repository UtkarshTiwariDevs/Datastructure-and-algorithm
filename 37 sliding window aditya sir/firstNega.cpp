#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int a[], int n, int k)
{
    vector<int> v;
    list<int> l;
    int i = 0, j = 0;
    while (j < n)
    {
        if (a[j] < 0)
        {
            l.push_back(a[j]);
        }

        if((j-i+1) < k)
        {
            j++;
        }
        else if((j-i+1) == k)
        {
            if(l.size() == 0)
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(l.front());
                if(a[i] == l.front())
                {
                    l.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    return v;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    vector<int> v = solve(a,n,k);
    for(auto i = v.begin() ; i != v.end() ;i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}