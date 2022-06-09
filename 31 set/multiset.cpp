#include<iostream>
#include<set>
using namespace std;

int main(){
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(5);

    for(auto i:s)
        cout<<i<<" ";
    
    cout<<endl;
 
    // s.erase(2);
    // for(auto i:s)
    //     cout<<i<<" ";
    
    s.erase(s.find(2));  //only one 2 will be deleted
    for(auto i: s)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}