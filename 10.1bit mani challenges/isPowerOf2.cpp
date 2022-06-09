#include <iostream>
using namespace std;

int isPowerOf2(int n)
{
    return (n && !(n & n - 1));
}

int main()
{
    cout << isPowerOf2(106) << endl;
    return 0;
}