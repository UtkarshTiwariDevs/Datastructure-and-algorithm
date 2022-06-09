#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int sumOfN(int num)
{
    int ans;
    ans = (num * (num + 1)) / 2;
    return ans;
}

int pytho(int a, int b, int c)
{
    int large, num1, num2;
    if (a > b)
    {
        if (a > c)
        {
            large = a;
            num1 = b;
            num2 = c;
        }
        else
        {
            large = c;
            num1 = b;
            num2 = a;
        }
    }
    else
    {
        if (b > c)
        {
            large = b;
            num1 = a;
            num2 = c;
        }
        else
        {
            large = c;
            num1 = b;
            num2 = a;
        }
    }
    if (pow(large, 2) == (pow(num1, 2) + pow(num2, 2)))
    {
        cout << "Yes they are Pythagorean Triples" << endl;
    }
    else
    {
        cout << "No they are not Pythagorean Triples" << endl;
    }
    return 0;
}

int main()
{
    /*int n;
    cin >> n;
    cout << sumOfN(n) << endl; */

    int a, b, c;
    // cout << "Enter 3 numbers to check they are pythgorean triples or not";
    cin >> a >> b >> c;
    pytho(a, b, c);
}