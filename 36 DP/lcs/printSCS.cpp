#include <bits/stdc++.h>
using namespace std;

string printSCS(string x, string y, int m, int n)
{
    int t[m + 1][n + 1];

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            t[i][j] = 0;
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    
    int i =m,j=n;
    string s= "";
    while (i>0 && j>0)
    {
        if(x[i-1] == y[j-1] )
        {
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i-1][j] > t[i][j-1])
            {
                s.push_back(x[i-1]);
                i--;
            }
            else // t[i][j-1] > t[i-1][j]
            {
                s.push_back(y[j-1]);
                j--;
            }
        }
    }
    //still we have empty both the strings
    while(i>0)
    {
        s.push_back(x[i-1]);
        i--;
    }
    while(j>0)
    {
        s.push_back(y[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    string x, y;
    cin >> x >> y;
    int m = x.length();
    int n = y.length();
    cout<<printSCS(x, y, m, n);
    return 0;
}