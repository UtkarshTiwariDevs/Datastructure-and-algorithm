#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int m1[n1][n2];
    int m2[n2][n3];

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin >> m1[i][j];
        }
    }
    
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cin >> m2[i][j];
        }
    }
    // initialise with 0
    int m3[n1][n3];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            m3[i][j] = 0;
        }
    }
    // multi
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            for (int k = 0; k < n2; k++)
            {
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // output
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cout << m3[1][j] << " ";
        }
        cout << endl;
    }
}