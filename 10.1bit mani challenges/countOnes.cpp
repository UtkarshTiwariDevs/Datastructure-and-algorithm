#include <iostream>
using namespace std;

int countOnes(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    cout << countOnes(106) << endl;
    return 0;
}