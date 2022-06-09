/*
Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Example 1:

Input:
txt = forxxorfxdofr
pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.
Example 2:

Input:
txt = aabaabaa
pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    unordered_map<char, int> m;

    vector<int> v;

    for (int x = 0; x < p.size(); x++)
        m[p[x]]++;

    int count = m.size() ;
    int i = 0, j = 0, k = p.size();

    while (j < s.size())
    {
        if (m.find(s[j]) != m.end())
        {
            m[s[j]]--;
            if (m[s[j]] == 0)
                count--;
        }

        if ((j - i + 1) < k)
            j++;

        else if ((j - i + 1) == k)
        {
            if (count == 0)
                v.push_back(i);

            if (m.find(s[i]) != m.end())
            {
                m[s[i]]++;
                if (m[s[i]] == 1)
                    count++;
            }
            i++;
            j++;
        }
    }
    return v;
}
int main()
{
    string txt = "aabaabaa";
    string pat = "aaba";
    vector<int> v = findAnagrams(txt, pat);
    // for(auto it : v)
    //     cout<<it<<" ";
    cout<<v.size();
    return 0;
}

// map<char, int> mp;
//     for (int i = 0; i < k; i++)
//     {
//         mp[ptr[i]]++;
//     }
//     for (auto i : mp)
//     {
//         cout << i.first << "  " << i.second << endl;
//     }
// map<int, int> m;
// for (int i = 0; i < n; i++)
//     m[arr[i]]++;

// cout << "Element  Frequency" << endl;
// for (auto i : m)
//     cout << i.first << "   " << i.second
//          << endl;
// return 0;

//
