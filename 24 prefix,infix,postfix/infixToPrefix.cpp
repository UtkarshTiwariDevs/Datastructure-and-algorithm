#include <iostream>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

int pre(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());
    // cout<<s<<endl;
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            result += s[i];
        }
        else if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && pre(st.top()) >= pre(s[i]))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    // cout << result << endl;
    return result;
}

int main()
{
    cout << infixToPrefix("(a-b/c)*(a/k-l)");
    return 0;
}
