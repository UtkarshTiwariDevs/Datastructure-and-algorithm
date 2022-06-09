#include <iostream>
#include <cmath>

using namespace std;

void fibbo(int num)
{
    int t1 = 0;
    int t2 = 1;

    for (int i = 1; i <= num; i++)
    {
        cout << t1 << endl;
        int newnum = t1 + t2;
        t1 = t2;
        t2 = newnum ;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    fibbo(n);
}