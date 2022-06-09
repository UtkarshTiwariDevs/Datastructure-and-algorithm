#include <bits/stdc++.h>
using namespace std;

class que
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int val)
    {
        s1.push(val);
    }

    void pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "empty" << endl;
            return;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
        stack<int> temp = s2;
        s1 = s2;
        s2 = temp;
    }
    int top(){
        if (s1.empty() && s2.empty())
            return -1;
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topvalue = s2.top();
        stack<int> temp = s2;
        s1 = s2;
        s2 = temp;
        return topvalue;
    }
    bool empty(){
        if (s1.empty() && s2.empty())
            return true;
        return false;
    }
};
int main()
{
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;

    cout<<q.empty()<<endl;
    return 0;
}