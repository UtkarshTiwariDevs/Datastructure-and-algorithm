#include <iostream>
using namespace std;

//check sorted array or not
bool sortedArr(int a[], int n)
{
    if (n == 1)
        return true;
    bool restArray = sortedArr(a + 1, n - 1);
    return (a[0] < a[1] && restArray);
}

//print number till n 
void printNdec(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    printNdec(n - 1);
}
void printNinc(int n)
{
    if (n == 0)
        return;
    printNinc(n - 1);
    cout << n << endl;
}

// first occurence of a num in array
int firstOccur(int a[], int n, int i, int key)
{
    if (i == n)
        return -1;
    if (a[i] == key)
        return i;
    return firstOccur(a, n, i + 1, key);
}
// last  occ of num in array
int lastOccur(int a[], int n, int i, int key)
{
    if (n == i)
        return -1;
    int restArray = lastOccur(a, n, i + 1, key);
    if (restArray != -1)
        return restArray;
    if (a[i] == key)
        return i;
    return -1;
}

int main()
{
    int a[] = {1, 2, 4, 6, 8, 9, 5, 4, 9};
    int n = 9;
    int key = 9;
    cout << lastOccur(a, n, 0, key);

    // int n;
    // cin>>n;
    // printNdec(n);
    // printNinc(n);
    return 0;
}