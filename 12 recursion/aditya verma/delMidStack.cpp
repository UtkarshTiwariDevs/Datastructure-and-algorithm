#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int> &s,int k){
    if(k==1){
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    solve(s,k-1);
    s.push(temp);
}
stack<int> delMid(stack<int> s,int size){
    if(s.size()==0){
        return s;
    }
    int k = (size/2)+1;
    solve(s,k);
    return s;
}
int main(){
    stack<int> s;
    int val;
    for(int i = 0;i<5;i++){
        cin>>val;
        s.push(val);
    }
    
    s = delMid(s,5);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}