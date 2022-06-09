#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int bitMatch(int n,int pos){
    return ((n & (1<<pos)) !=0);
}

int main(){
    cout<<bitMatch(75,2)<<endl;
    return 0;
}