#include <iostream>
using namespace std;

int sumOfNint(int n)
{
    if (n==0)
        return 0;
    return n+sumOfNint(n-1);
}

int ntoPowerP(int n, int p)
{
    if (p==0)
        return 1;
    return n*ntoPowerP(n,p-1);
}

int factorial(int n)
{
    if(n==0)
        return 1;
    return n*factorial(n-1);
}

int febbo(int n)
{
    //0 1 1 2 3 5 8 let 1st term = 1
    if(n==0 || n==1)
        return n;
    return febbo(n-1) + febbo(n-2);
}

int main()
{
    int n;
    cin>>n;
    cout<<febbo(n);

    return 0;
}