#include<iostream>
using namespace std;

int updaterBit(int n, int pos, int value)
{
    int mask = ~(1 << pos);
    n = (n & mask);
    return (n | (value << pos));
}

int main()
{
    cout << updaterBit(5, 2, 1) << endl;
    cout<<"hello";
    return 0;
}