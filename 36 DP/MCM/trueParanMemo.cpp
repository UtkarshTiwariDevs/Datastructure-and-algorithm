/*
Evaluate Expression To True-Boolean Parenthesization Recursion
Given a boolean expression with following symbols.
Symbols
    'T' --- true
    'F' --- false
And following operators filled between symbols
Operators
    &   ---boolean AND
    |   --- boolean OR
    ^   --- boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
Example:
Input: symbol[]    = {T, F, T}
       operator[]  = {^, &}
Output: 2
The given expression is "T ^ F & T", it evaluates true
in two ways "((T ^ F) & T)" and "(T ^ (F & T))"
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int solve(string s, int i, int j, bool isTrue)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue == true)
        {
            return s[i] == 'T';
        }
        else
        {
            return s[i] == 'F';
        }
    }

    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(isTrue));

    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }

    int ans = 0;

    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int lT = solve(s, i, k - 1, true);
        int lF = solve(s, i, k - 1, false);
        int rT = solve(s, k + 1, j, true);
        int rF = solve(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (isTrue == true)
            {
                ans += (lT * rT);
            }
            else
            {
                ans += (lT * rF) + (lF * rT) + (lF * rF);
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue == true)
            {
                ans += (lT * rF) + (lF * rT) + (lT * rT);
            }
            else
            {
                ans += (lF * rF);
            }
        }
        else if (s[k] == '^')
        {
            if (isTrue == true)
            {
                ans += (lT * rF) + (lF * rT);
            }
            else
            {
                ans += (lT * rT) + (lF * rF);
            }
        }
    }
    return mp[temp] = ans;
}

int main()
{
    string s = "T|F&T^F";
    int i = 0;
    int j = s.length() - 1;
    cout << solve(s, i, j, true);
    return 0;
}