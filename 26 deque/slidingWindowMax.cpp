#include<bits/stdc++.h>

using namespace std;
class Solution{
    public:
    vector<int> maxSlidingWindow(vector<int> &nums,int k){
        deque<int> dq;
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

int main(){
    // int n,k;
    // cin>>n>>k;
    // int arr[n];
    // for(int i=0 ;i<n;i++)
    //     cin>>arr[i];

    // int maxi=0;
    // for(int i = 0;i<=n-k;i++){
    //     maxi = arr[i];
    //     for(int j =0;j<k;j++){
    //         maxi = max(maxi,arr[i+j]);
    //     }
    //     cout<<maxi<<" ";
    // }
    Solution sol;
    vector<int> n={1,3,-1,-3,5,3,6,7};
    vector<int> ans = sol.maxSlidingWindow(n,3);
    for(auto i: ans)
        cout<<i<<" ";
    return 0;
}