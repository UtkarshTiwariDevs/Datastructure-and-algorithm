#include<iostream>
using namespace std;

//print 1 to n
void printNum(int n){
    if(n==1){
        cout<<n<<" ";
        return;
    }

    printNum(n-1);
    cout<<n<<" ";
}

//print n to 1
void printNumRev(int n){
    if(n==1){
        cout<<n<<" ";
        return;
    }
    cout<<n<<" ";
    printNumRev(n-1);
}

//print factorial
int factorialPrint(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }

    return n * factorialPrint(n-1);
}
int main(){
    printNum(5);
    cout<<endl;
    printNumRev(5);
    cout<<endl;
    cout<<factorialPrint(4);
    return 0;
}