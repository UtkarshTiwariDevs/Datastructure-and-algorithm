#include <iostream>
using namespace std;

//reverse a string
void reverse(string s)
{
    if(s.length()==0)
        return ;
    string ros = s.substr(1);
    reverse(ros);
    cout<<s[0];
}

//replace pi with 3.14
void replacePi(string s)
{
    if(s.length()==0)
        return;
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        replacePi(s.substr(2));
    }
    else{
        cout<<s[0];
        replacePi(s.substr(1));
    }
}

//tower of hanoi
void towerOfHanoi(int n,char src,char dest,char helper)
{
    if(n==0)
        return;
    towerOfHanoi(n-1,src,helper,dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1,helper,dest,src);
}

//remove duplicates from string
string remDuplicates(string s)
{
    if(s.length()==0)
        return "";
    char ch =s[0];
    string ros=remDuplicates(s.substr(1));
    if(ch == ros[0]){
        return ros;
    }
    
    return ch+ros;
}

//move x to end
string moveX(string s)
{
    if(s.length()==0)
        return "";
    char ch = s[0];
    string ros = moveX(s.substr(1));
    if(ch=='x'){
        return ros + ch;
    }
    return ch+ros;
}
//print substrings
void substrings(string s,string ans)
{
    if(s.length()==0)
        cout<<ans<<endl;
        return;
    char ch = s[0];
    string ros = s.substr(1);
    substrings(ros,ans);
    substrings(ros,ans+ch);

}

int main()
{
    
    substrings("ABC","");
    cout<<endl;
    return 0;
}