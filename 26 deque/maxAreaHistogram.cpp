#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int largestRectangleArea(vector<int> &heights){
        int n = heights.size();
        stack<int> st;
        int leftSmall[n],rightSmall[n];
        
        for(int i=0;i<n;i++){
            while (!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
                leftSmall[i];
            else 
                leftSmall[i] = st.top()+1;
            st.push(i);
        }
        //clear stack to reuse
        while (!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while (!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
                rightSmall[i] = n-1;
            else
                rightSmall[i]= st.top() -1;
            st.push(i);
        }
        int maxA = 0;
        for(int i=0;i<n;i++){
            maxA = max(maxA,heights[i] * (rightSmall[i] -leftSmall[i] + 1));
        }
        
        return maxA;
    }
};
int main(){
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    cout<<sol.largestRectangleArea(heights);
    return 0;
}