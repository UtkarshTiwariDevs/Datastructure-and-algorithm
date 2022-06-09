/*
Input 1:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
Output 1:
    C = [3, 3, 5, 5, 6, 7]
    */

#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int a[], int k, int n)
{
    vector<int> v;
    list<int> l;
    int i = 0, j = 1;
    l.push_back(a[0]);

    while (j < n)
    {
        if (a[j] > a[j - 1])
        {
            l.push_back(a[j]);
        }
        if ((j - i + 1) < k)
            j++;
        else if ((j - i + 1) == k)
        {
            v.push_back(l.back());
            if(a[i] == l.front())
                l.pop_front();
            i++;
            j++;
        }
    }
    return v;
}
int main()
{
    int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v=solve(a,k,n);
    for(auto it : v)
        cout<<it<<" ";
    return 0;
}