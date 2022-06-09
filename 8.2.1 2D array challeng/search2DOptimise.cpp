#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, key;
    cin >> n >> m >> key;
    int a[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int r=0,c=m-1;
    bool check=false;
    while(r<n and c>=0){
        if(a[r][c]==key){
            cout<<"Found at "<<r<<" "<<c;
            check=true;
            break;
        }
        else if (a[r][c]>key){
            c--;
        }
        else{
            r++;
        }
    }
    if(check==0){
        cout<<"Element not found";
    }
}