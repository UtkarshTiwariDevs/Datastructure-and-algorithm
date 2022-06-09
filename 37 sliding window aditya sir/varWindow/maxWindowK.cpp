/*
Problem Description:

Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.

For Input:
1
7 5
4 1 1 1 2 3 5
your output is:
4
*/
//for positive int only
#include <bits/stdc++.h>
using namespace std;
int solve(int a[], int n, int k)
{
    int i = 0, j = 0, ans = 0, sum = 0;
    while (j < n)
    {
        sum = sum + a[j];
        if (sum < k)
            j++;
        else if (sum == k)
        {
            ans = max(ans, (j - i + 1));
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum = sum - a[i];
                i++;
            }
            j++;
        }
    }
    return ans;
}
int main()
{
    int a[] = {4, 1, 1, 1, 2, 3, 5};
    int n = 7;
    int k = 5;
    cout << solve(a, n, k);
    return 0;
}

// int solve(vector<int> &A, const int &k) {
// 	int n = A.size();
// 	int i = 0, j = 0, sum = 0;
// 	int mx = INT_MIN;
// 	while (j < n) {
// 		sum += A[j];
// 		if (sum < k) {
// 			j++;
// 		} else if (sum == k) {
// 			mx = max(mx, j - i + 1);
// 			j++;
// 		} else if (sum > k) {
// 			while (sum > k) {
// 				sum = sum - A[i];
// 				i++;
// 			}
// 			j++;
// 		}
// 	}
// 	return mx;
// }