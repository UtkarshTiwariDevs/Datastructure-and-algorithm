#include<bits/stdc++.h>
using namespace std;

// very important check palin in range
// bool isPalindrome(string s ,int i,int j){
//     string p = "";
//     for(int m = i;m<j;m++){
//         p = p+ s[m];
//     }
//     reverse(p.begin(),p.end());
//     for(int m = i;m<j;m++){
//         if(p[m-i] != s[m]){
//             return false;
//         }
//     }
//     return true;
// }
// int main(){
//     string s= "aaabcba";
//     // isPalindrome(s,2,7);
//     if(isPalindrome(s,2,7)){
//         cout<<1;
//     }
//     else{
//         cout<<0;
//     }
//     return 0;
// }

bool isPalindrome(string s ,int i,int j){
    string p = "";
    for(int m = i;m<=j;m++){
        p = p+ s[m];
    }
    reverse(p.begin(),p.end());
    for(int m = i;m<=j;m++){
        if(p[m-i] != s[m]){
            return false;
        }
    }
    return true;
}

int solve(string s ,int i , int j){
    if(i>=j){
        return 0;
    }
    if(isPalindrome(s,i,j) == true){
        return 0;
    }

    int mn = INT_MAX;
    for(int k = i;k<=j-1 ;k++){
        int tempAns = solve(s,i,k) + solve(s,k+1,j) + 1;
        if(tempAns<mn){
            mn = tempAns;
        }
    }
    return mn;
}
int main(){
    string s= "nitinin";
    // cout<<isPalindrome(s,0,s.length()-1);
    cout<<solve(s,0,s.length()-1);
}