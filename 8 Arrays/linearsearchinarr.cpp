#include<iostream>
using namespace std;
int linearSearch(int arr[],int n,int searchitem){
    for(int i=0;i<n;i++){
        if(arr[i]==searchitem){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int searchitem;
    cin>>searchitem;
    
    int position = linearSearch(arr,n,searchitem);
    if(position>-1){
        cout<<"Elemennt found as index "<<position<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }


}