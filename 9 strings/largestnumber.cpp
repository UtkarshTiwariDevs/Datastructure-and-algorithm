#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string s = "875636780970980";
    sort(s.begin(),s.end(),greater<int>());
    cout<<s;
}