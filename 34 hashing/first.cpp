#include<iostream>
#include<unordered_set>

using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(12);
    s.insert(123);
    s.insert(31);
    s.insert(18);

    for(auto i : s)
        cout<<i<<" ";
    cout<<endl;
    for(auto it = s.begin() ; it!=s.end() ;it++)
        cout<<*it<<" ";
    cout<<endl;

    if(s.find(12) == s.end()){
        cout<<"Not fount"<<endl;
    }
    else{
        cout<<"Found"<<endl;
    }

    s.erase(12);
    s.erase(s.begin(),s.end());
    cout<<endl;
    for(auto i : s)
        cout<<i<<" ";

    return 0;
}