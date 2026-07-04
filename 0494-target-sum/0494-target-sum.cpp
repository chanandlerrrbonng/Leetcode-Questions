class Solution {
public:
    int f(int idx, int t, vector<int>& nums, vector<vector<int>>& dp, int totsum){
        if(idx<0) return t==0? 1: 0;
        if (t < -totsum || t > totsum) return 0;
        if(dp[idx][t+totsum]!=-1) return dp[idx][t+totsum];
        int add=f(idx-1, t-nums[idx], nums, dp, totsum);
        int sub=f(idx-1, t+nums[idx], nums, dp, totsum);
        return dp[idx][t+totsum]=add+sub;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totsum=0;
        for(auto it:nums){
            totsum+=it;
        }
        if (abs(target) > totsum) return 0;
        vector<vector<int>>dp(n, vector<int>(2*totsum+1, -1));

        return f(n-1, target, nums, dp, totsum);
        
    }
};