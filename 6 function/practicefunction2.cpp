#include<bits/stdc++.h>

using namespace std;

int binarytodecimal(int n){
    int ans=0;
    int x=1;

    while(n>0){
        int lastdigit=n%10;
        ans+=lastdigit*x;
        x*=2;
        n/=10;
    }
    return ans;
}

int octaltodecimal(int n){
    int ans=0;
    int x=1;

    while(n>0){
        int lastdigit=n%10;
        ans+=lastdigit*x;
        x*=8;
        n/=10;
    }
    return ans;
}
int hexadecimalToDecimal(string n){
    int ans=0;
    int x=1;
    int s = n.size();

    for(int i=s-1;i>=0;i--){
        if(n[i]>='0' && n[i]<='9'){
            ans+=x*(n[i]-'0');
        }
        else if(n[i]>='A' && n[i]<='F'){
            ans+=x*(n[i]-'A'+10);
        }
        x*=16;
    }
    return ans;
}
int decimalToBinary(int n){
    int num =0;
    while(n>0){
        int rem = n%2;
        num = num*10+rem;
        n/=2;
    }
    int rev_num =0;
    while (num>0)
    {
        int rem  =num%10;
        rev_num = rev_num*10+rem;
        num/=10;
    }
    
    return rev_num;
}
int decimalToOctal(int n){
    int num =0;
    while(n>0){
        int rem = n%8;
        num = num*10+rem;
        n/=8;
    }
    int rev_num =0;
    while (num>0)
    {
        int rem  =num%10;
        rev_num = rev_num*10+rem;
        num/=10;
    }
    
    return rev_num;
}
int32_t main(){
    int n;
    // string n;
    cin>>n;
    // cout<<binarytodecimal(n)<<endl;
    // cout<<octaltodecimal(n)<<endl;
    cout<<decimalToOctal(n);
    return 0;
} 