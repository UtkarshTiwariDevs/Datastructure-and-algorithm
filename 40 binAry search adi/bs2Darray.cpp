#include <bits/stdc++.h>
using namespace std;

pair<int,int> bs2D(int n,int m,int a[4][4],int key)
{
    int i=0,j=m-1;
    pair<int,int> p;
    while(i>=0 && i<n && j>=0 && j<m)
    {
        if(a[i][j] == key)
        {
            p.first = i;
            p.second = j;
            return p;
        }
        else if(a[i][j] > key)
            j--;
        else
            i++;
    }
    p.first =-1;
    p.second = -1;
    return p;
}
int main()
{
    int a[4][4] = {{10,20,30,40},
                   {15,25,35,45},
                   {27,29,37,45},
                   {32,35,39,50}};
    // for(int i =0;i<4;i++)
    // {
    //     for(int j=0;j<4;j++)
    //         cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }
    int n=4,m=4;
    int key =23;
    pair<int,int> p = bs2D(n,m,a,key);
    cout<<"["<<p.first<<","<<p.second<<"]";
    return 0;
}