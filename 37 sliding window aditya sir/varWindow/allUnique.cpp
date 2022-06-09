/*
Example:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring
*/

#include <bits/stdc++.h>
using namespace std;
int solve(string s, int n)
{
    int i = 0, j = 0, ans = INT_MIN;
    unordered_map<int, int> m;

    while (j < n)
    {
        m[s[j]]++;
        if (m.size() == (j - i + 1))
        {
            ans = max(ans, j - i + 1);
            j++;
        }

        else if (m.size() < (j - i + 1))
        {
            while (m.size() < (j - i + 1))
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
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
    string s = "pwwkew"; //op = 3
    int n = s.size();
    cout << solve(s, n);
    return 0;
}