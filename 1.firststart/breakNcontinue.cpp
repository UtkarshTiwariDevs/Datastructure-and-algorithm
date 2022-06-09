#include<iostream>
using namespace std;

int main(){
/*    int pocketMoney=3000;

    for (int i = 0; i <= 30 ; i++)
    {
        if (i%2==0){
            continue;
        }
        if (pocketMoney <= 0){
            break;
        }
        cout<<"You can go out today"<<endl;
        pocketMoney = pocketMoney - 300;
    }
*/
    //print number from 1 to 100 while skipping num divi by 3
 /*   for (int i = 1; i <= 100; i++)
    {
        if (i%3==0){
            continue;
        }
        cout<<i<<" ";
    }
 */   

    int i;
    int n;
    cin>>n;
    for(i = 2;i<n;i++){
        if (n%i==0){
            cout<<"non prime"<<endl;
            break;
        }
    }
    if (i==n){
        cout<<"prime"<<endl;
    }
    
    return 0;


}