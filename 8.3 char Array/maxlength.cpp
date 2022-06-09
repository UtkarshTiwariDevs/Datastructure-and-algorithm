#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    char a[n + 1];
    cin.getline(a, n);
    cin.ignore();

    int i = 0;
    int curLength = 0;
    int maxLength = 0;
    int st = 0, maxst = 0;

    while (1)
    {
        if (a[i] == ' ' or a[i] == '\0')
        {
            if (curLength > maxLength)
            {
                maxLength = curLength;
                maxst = st;
            }
            curLength = 0;
            st = i + 1;
        }
        else
        {
            curLength++;
        }
        if (a[i] == '\0')
        {
            break;
        }
        i++;
    }
    cout << maxLength << endl;
    for (int i = 0; i < maxLength; i++)
    {
        cout << a[i + maxst];
    }
}