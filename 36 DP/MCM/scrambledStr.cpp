/*
Scramble String using Recursion
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of A = “great”:
 great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.
*/
#include <bits/stdc++.h>
using namespace std;

bool solve(string a, string b)
{
    if (a.compare(b) == 0)
    { // compare output == 0 when same otherwise 1
        return true;
    }
    if (a.length() <= 1)
    {
        return false;
    }
    int n = a.length();
    bool flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        if (((solve(a.substr(0, i), b.substr(n - i, i)) == true) && (solve(a.substr(i, n - i), b.substr(0, n - i)) == true)) ||
            ((solve(a.substr(0, i), b.substr(0, i)) == true) && (solve(a.substr(i, n - i), b.substr(i, n - i)) == true)))
        {
            flag = true;
            break;
        }
    }
    return flag;
}
int main()
{
    string a, b;
    cin >> a >> b;

    if (a.length() != b.length())
    {
        return false;
    }
    if (a.empty() && b.empty())
    {
        return true;
    }
    cout << solve(a, b);
    return 0;
}