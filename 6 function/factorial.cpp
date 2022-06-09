#include <iostream>
#include <cmath>

using namespace std;
int facto(int num)
{
    int result = 1;
    if (num == 0)
    {
        return 1;
    }
    else if (num == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 2; i <= num; i++)
        {
            result *= i;
        }
    }
    return result;
}
int main()
{
    int n;
    cin >> n;
    cout << facto(n);
}