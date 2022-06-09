#include<iostream>
using namespace std;

int feasibility(int boards[],int n,int limit){
    int sum =0 ,painter = 1;
    for(int i =0;i<n;i++){
        sum += boards[i];
        if(sum>limit){
            sum = boards[i];
            painter++;
        }
    }
    return painter;
}
int painterPartition(int boards[],int n,int m){
    int totalLength =0,k=0;
    for(int i =0;i<n;i++){
        k=max(k,boards[i]);
        totalLength += boards[i];
    }
    int low = k, high= totalLength;
    while (low<high)
    {
        int mid =(low+high)/2;
        int painters= feasibility(boards,n,mid);
        if(painters<=m){
            high = mid;
        }
        else{
            low =mid+1;
        }
    }
    return low;
}
int main(){
    int boards[] ={10,20,30,40};
    int n = 4;
    int m =2;
    cout<<painterPartition(boards,n,m);
    return 0;
}