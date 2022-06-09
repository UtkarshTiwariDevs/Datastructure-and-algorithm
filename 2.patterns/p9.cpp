#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (count % 2 == 0)
            {
                cout << "0 ";
            }
            else
            {
                cout << "1 ";
            }
            count++;
        }
        cout << endl;
    }
}