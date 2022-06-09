#include<bits/stdc++.h>
using namespace std;

struct Activity{
    int start;
    int finish;
};
void printMaxActivity(Activity arr[],int n){
    sort(arr,arr+n,arr->finish);

    int i = 0 ;
    cout<<arr[i].start<<","<<arr[i].finish<<endl;
    for(int j =1;j<n;j++){
        if(arr[j].start>=arr[i].finish){
            cout<<arr[j].start<<","<<arr[j].finish<<endl;
            i=j;
        }
    }
}
int main(){
    Activity arr[] = {{0,6},{3,4},{1,2},{5,9},{5,7},{8,9}};
    int n =6;
    printMaxActivity(arr,n);
    return 0;
}
//not working