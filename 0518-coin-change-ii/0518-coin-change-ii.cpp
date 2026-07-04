class Solution {
public:
    int f(int idx, int amt, vector<int>&coins, vector<vector<int>>&dp){
        if(amt==0) return 1;
        if(idx==0 && amt%coins[idx]==0) return 1;
        if(idx==0 && amt%coins[idx]!=0) return 0;
        if(dp[idx][amt]!=-1) return dp[idx][amt];

        int nottake=f(idx-1, amt, coins, dp);
        int take=0;
        if(coins[idx]<=amt) take=f(idx, amt-coins[idx], coins, dp);
        return dp[idx][amt]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans=f(n-1, amount, coins, dp);
        return ans;
    }
};