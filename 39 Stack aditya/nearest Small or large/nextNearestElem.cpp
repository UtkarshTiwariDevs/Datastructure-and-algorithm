#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

// vector<int> NLE(int n,int arr[])
// {
//     vec ans(n,-1);
//     for(int i = 0;i<n-1;i++)
//     {
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[j] > arr[i])
//             {
//                 ans[i] = arr[j];
//                 break;
//             }
//         }
//     }
//     return ans;                                              brute
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//         cin>>arr[i];

//     vec ans = NLE(n,arr);
//     for(auto it : ans)
//         cout<<it<<" ";

//     return 0;
// }

void NLE(int n, int arr[])
{
    vec v;
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.size() == 0)
            v.push_back(-1);
        else if (st.size() > 0 && st.top() > arr[i])
            v.push_back(st.top());
        else if (st.size() > 0 && st.top() <= arr[i])
        {
            while (st.size() > 0 && st.top() <= arr[i])
                st.pop();
            if (st.size() == 0)
                v.push_back(-1);
            else
                v.push_back(st.top());
        }
        st.push(arr[i]);
    }
    reverse(v.begin(), v.end());
    for(auto it : v)
        cout<<it<<" ";
}
 
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    NLE(n,arr);
    // vec ans = NLE(n, arr);
    // for (auto it : ans)
    //     cout << it << " ";

    return 0;
}

// correct code at gfg
