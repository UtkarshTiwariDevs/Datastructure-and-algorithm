#include <iostream>
#include <vector>

using namespace std;

void insert(vector<int> &v, int temp)
{
    if (v.size() == 0 || v[v.size() - 1] <= temp)
    {
        v.push_back(temp);
        return;
    }
    int val = v[v.size() - 1];
    v.pop_back();
    insert(v, temp );
    v.push_back(val);
    return;
}
void sort(vector<int> &v)
{
    if (v.size() == 1)
    {
        return;
    }
    int temp = v[v.size() - 1];
    v.pop_back();
    sort(v);
    insert(v, temp);
    return;
}
int main()
{
    vector<int> v;
    int n, input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    sort(v);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}