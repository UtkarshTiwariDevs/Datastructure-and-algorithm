#include <bits/stdc++.h>
using namespace std;

int infSortedArr(int a[],int key)
{
    int s =0;
    int e =1;
    while(a[e] < key)
    {
        s = e;
        e = 2*e;
    }
    while(s<=e)
    {
        int m =(s+e)/2;
        if(a[m] == key)
            return m;
        else if(a[m] > key)
            e = m -1;
        else
            s = m +1;
    }
    return -1;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5,6,7,8,9,10,11,12,13,14,15,16}; //infi arr
    int key =7;
    
    cout<<infSortedArr(a,key);
    return 0;
}
