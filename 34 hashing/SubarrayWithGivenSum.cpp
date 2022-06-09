#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    int a[] = {10, 15, -5, 15, -10, 5};
    int n = 6;
    int count = 0;
    for (int i=0; i <n; i++)
    {
        // Pick ending point
        for (int j=i; j<n; j++)
        {   
            int sum = 0;
            // Print subarray between current starting
            // and ending points
            for (int k=i; k<=j; k++){
                sum = sum + a[k];
                if(sum ==5){
                    count++;
                }
            }
        }
    }
    cout<<count;
    return 0;
}