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

    bool check = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == key)
            {
                cout << "element found at " << i << " " << j << endl;
                check = 1;
                break;
            }
        }
    }
    if (check == 0)
    {
        cout << "element not found" << endl;
    }
}