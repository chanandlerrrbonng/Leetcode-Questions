class Solution {
public:
    int f(int idx, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>>&dp){
        if(idx==n) return 0;
        if(cap==2) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        int price=0;
        if(buy){
            price=max(-prices[idx]+f(idx+1, !buy, cap, prices, n, dp), f(idx+1, buy, cap, prices, n, dp));
        } else {
            price=max(prices[idx]+f(idx+1, !buy, cap+1, prices, n, dp), f(idx+1, buy, cap, prices, n, dp));
        }
        return dp[idx][buy][cap]=price;

    }
    int maxProfit(vector<int>& prices) {
        int cnt=0;
        int n=prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, cnt, prices, n, dp);
        
    }
};