#include <iostream>
using namespace std;

#define n 100

class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    //push operation
    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"Stack Overflow\n";
            return;
        }
        top++;
        arr[top]=x;
    }
    //pop operation
    void pop(){
        if(top==-1)
        {
            cout<<"Stack Underflow\n";
            return;
        }
        top--;
    }
    //top
    int Top(){
        if(top==-1){
            cout<<"Stack Underflow\n";
            return -1;
        }
        cout<<"\n";
        return arr[top];
    }
    //empty
    bool empty(){
        cout<<"\n";
        return top==-1;
    }
};


int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.Top();
    s.pop();
    cout<<s.Top();
    return 0;
}
