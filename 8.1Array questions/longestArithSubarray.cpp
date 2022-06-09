#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 2;
    int pd = arr[1] - arr[0];
    int cd = 2;
    int j = 2;
    while (j < n)
    {
        if (pd == arr[j] - arr[j - 1])
        {
            cd++;
        }
        else
        {
            pd = arr[j] - arr[j - 1];
            cd = 2;
        }
        ans = max(ans, cd);
        j++;
    }
    cout << ans;
}