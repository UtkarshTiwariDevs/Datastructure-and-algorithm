#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int> &s,int temp){
    if(s.size()== 0){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
}
void reverse(stack<int> &s){
    if(s.size()== 0){
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    insert(s,temp);
}
int main(){
    stack<int> s;
    int val;
    for(int i = 0;i<5;i++){
        cin>>val;
        s.push(val);
    }

    reverse(s);
    cout<<"New output  ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}