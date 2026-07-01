class Solution {
public:
    vector<int>dp;
    int solve(int idx, vector<int>& nums){
        if(idx==0) return nums[0];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take=nums[idx]+solve(idx-2, nums);
        int nottake=solve(idx-1, nums);
        return dp[idx]=max(take, nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,-1);
        return solve(n-1, nums);
    }
};