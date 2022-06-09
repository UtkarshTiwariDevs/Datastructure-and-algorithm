#include<iostream>
#include<deque>

using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(4);
    dq.push_front(1);
    dq.push_back(8);
    for(auto i:dq){
        cout<<i<<" ";
    }
    cout<<endl;
    dq.pop_back();
    for(auto i:dq)
        cout<<i<<" ";
    cout<<endl;
    cout<<dq.size();
}