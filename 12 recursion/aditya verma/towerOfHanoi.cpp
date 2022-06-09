#include <iostream>
using namespace std;

void solve(char s,char d,char h,int n,int &count){
    if(n==0){
        return;
    }
    solve(s,h,d,n-1,count);
    count++;
    cout<<"moving plate "<<n<<" from "<<s<<" to "<<d<<endl;
    solve(h,d,s,n-1,count);
}
int main()
{
    int n;
    cin >> n;
    int count = 0;
    solve('A','C','B',n,count);
    cout<<count;
    return 0;
}