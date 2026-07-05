class Solution {
public:
    int f(int idx, int buy, vector<int>& prices, int n, vector<vector<int>>&dp, int fee){
        if(idx>=n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int price=0;
        if(buy){
            price=max(-prices[idx]+f(idx+1, !buy, prices, n, dp, fee), f(idx+1, buy, prices, n, dp, fee));
        } else{
            price=max(prices[idx]+f(idx+1, !buy, prices, n, dp, fee)-fee, f(idx+1, buy, prices, n, dp, fee));
        }
        return dp[idx][buy]=price;
    }
    int maxProfit(vector<int>& prices, int& fee) {
        int n=prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return f(0, 1, prices, n, dp, fee);
        
    }
};