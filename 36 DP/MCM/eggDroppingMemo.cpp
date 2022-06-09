/*
Egg Dropping using Recursion
Problem statement: You are given N floor and K eggs. You have to minimize the number of times you have to drop the eggs to find the critical floor where critical floor means the floor beyond which eggs start to break. Assumptions of the problem:

If egg breaks at ith floor then it also breaks at all greater floors.
If egg does not break at ith floor then it does not break at all lower floors.
Unbroken egg can be used again.
Note: You have to find minimum trials required to find the critical floor not the critical floor.

Example:
Input:
    4
    2
    
    Output:
    Number of trials when number of eggs is 2 and number of floors is 4: 3
    */

#include<bits/stdc++.h>
using namespace std;
int static t[11][51];
int solve(int e,int f){
    if(f==0 || f==1){
        return f;
    }

    if(e==1){
        return f;  //worst case
    }
    if(t[e][f] != -1){
        return t[e][f];
    }

    int mn =INT_MAX;
    for(int k=1;k<=f;k++){
        int temp = 1+max(solve(e-1,k-1), solve(e,f-k));

        mn = min(mn,temp);
    }
    return t[e][f] = mn;
}
int main(){
    int e , f;
    cin>>e>>f;
    memset(t,-1,sizeof(t));
    cout<<solve(e,f);
    return 0;
}

/*
class Solution {
public:
    
    int solve(int k, int n, vector<vector<int>>& memo){
        if(n == 0 || n == 1) return n;
        if(k == 1) return n;
        
        if(memo[k][n] != -1) return memo[k][n];
        
        int mn = INT_MAX, low = 0, high = n, temp = 0;
        
        while(low<=high){
            
            int mid = (low + high)/2;
            
            int left = solve(k-1, mid-1, memo);
            int right = solve(k, n-mid, memo);
            
            temp = 1 + max(left, right);
            
            if(left < right) 
                low = mid+1;
            else 
                high = mid-1;    
    
            mn = min(mn, temp); 
        }
        return memo[k][n] = mn;
    }
    
    int superEggDrop(int k, int n) {
        //k =eggs and n = floor
        vector<vector<int>> memo(k+1, vector<int>(n+1, -1));
        return solve(k, n, memo);
    }
};

*/