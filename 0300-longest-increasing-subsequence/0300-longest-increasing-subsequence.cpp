class Solution {
public:
    int f(int idx, int previdx, vector<int>&nums, vector<vector<int>>&dp){
        if(idx<0) return 0;

        if(dp[idx][previdx+1]!=-1) return dp[idx][previdx+1];
        int take=0;
        if(previdx==-1 || nums[idx]<nums[previdx]) take=1+f(idx-1, idx, nums, dp);
        int nottake=f(idx-1, previdx, nums, dp);
        return dp[idx][previdx+1]=max(nottake, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return f(n-1, -1, nums, dp);
    }
};