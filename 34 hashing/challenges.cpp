#include <iostream>
#include <unordered_set>
#include <array>

using namespace std;
// distinct
int distinct(int a[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    return s.size();
}

// union of two array then return size of distinct
int union2array(int a[], int b[], int n, int m)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(b[i]);
    }
    return s.size();
}

// intersion of 2 array
void intersection2Array(int a[], int b[], int n, int m)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
    }
    int count = 0;
    for(int i=0;i<m;i++){
        if(s.find(b[i])==s.end()){
            s.erase(b[i]);
        }
        else{
            count++;
        }
    }
    cout<<count<<endl;
    cout<<s.size();
}
int main()
{
    int a[] = {1, 34, 34, 5, 67, 67, 88, 8, 8};
    int b[] = {1, 55, 5, 5, 67, 3, 8, 8};
    int n = 9;
    int m = 8;
    cout << distinct(a, n) << endl;

    cout << union2array(a, b, n, m) << endl;

    intersection2Array(a,b,n,m);
    return 0;
}