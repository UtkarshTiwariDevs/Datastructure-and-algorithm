#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int newnum = 0;
    int m=n;
    while (n > 0)
    {
        int lastdigit = n % 10;
        newnum += (lastdigit*lastdigit*lastdigit);
        // newnum+=pow(lastdigit,3); not working for 153
        n = n / 10;
    }

    if (newnum == m)
    {
        cout << "Armstrong";
    }
    else
    {
        cout << "Not Armstrong";
    }
}