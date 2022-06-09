/*
Given a string you need to print the size of the longest possible substring
that has exactly k unique characters.


Example:
Input:
2
aabacbebebe
3
aaaa
1
Output:
7
4
*/

#include <bits/stdc++.h>
using namespace std;
int solve(string s, int n, int k)
{
    int i = 0, j = 0, ans = INT_MIN;
    unordered_map<char, int> m;
    m.clear();

    while (j < n)
    {
        m[s[j]]++;
        if(m.size() < k)
            j++;
        else if(m.size() == k){
            ans = max(ans ,( j-i+1));
            j++;
        }
        else if(m.size() > k)
        {
            while(m.size() > k)
            {
                m[s[i]]--;
                if(m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return ans;
}
int main()
{
    string s = "aabacbebebe";
    int n = s.size();
    // cout<<n;
    int k = 3;
    cout << solve(s, n, k);
    return 0;
}