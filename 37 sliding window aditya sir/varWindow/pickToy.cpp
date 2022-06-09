/*
John is at a toy store help him pick maximum number of toys. He can only 
select in a continuous manner and he can select only two types of toys.


Example:
Input:
1
s : abaccab
o = 4 (acca)
*/

//actually ques similar hai k unique vale size

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
    string s = "abaccab";  //type of toys
    int n = s.size();
    // cout<<n;
    int k = 2; // two type toy
    cout << solve(s, n, k);
    return 0;
}