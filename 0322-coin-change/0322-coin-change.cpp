class Solution {
public:
    int f(int idx, int amt, vector<int>& coins, vector<vector<int>>&dp){
        if(amt==0) return 0;
        if(idx==0 && amt%coins[idx]==0) return amt/coins[idx];
        if(idx==0 && amt%coins[idx]!=0) return INT_MAX;
        if(dp[idx][amt]!=-1) return dp[idx][amt];

        int nottake=f(idx-1, amt, coins, dp);
        int take=INT_MAX;
        if(coins[idx]<=amt){int res=f(idx, amt-coins[idx], coins, dp);
        if(res!=INT_MAX) take=1+res;}
        return dp[idx][amt]=min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans=f(n-1, amount, coins, dp);
        return ans==INT_MAX? -1:ans;
    }
};