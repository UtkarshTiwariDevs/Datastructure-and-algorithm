#include<bits/stdc++.h>
using namespace std;

stack<int> s;
stack<int> ss;

void push(int a)
{
    s.push(a);
    cout<<a<<" Pushed\n";
    if(ss.size() == 0 || a <= ss.top())
        ss.push(a);
}
void pop()
{
    if(s.size()==0)
    {
        cout<<"Nothing to pop";
        return;
    }
    int ans = s.top();
    s.pop();
    cout<<ans<<" Poped \n";
    if(ss.top() == ans)
        ss.pop();
}
int getmin()
{
    if(ss.size() == 0)
        return -1;
    return ss.top();
}
int main()
{
    push(7);
    push(72);
    push(22);
    push(5);
    push(4);
    
    cout<<getmin()<<" is min in stack\n";
    pop();
    cout<<getmin()<<" is min in stack\n";
    
    return 0;
}