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
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=1; j++){
                for(int k=1; k>=0; k--){
                    if(j==0){
                        dp[i][j][k]=max(prices[i]+dp[i+1][1][k+1], dp[i+1][0][k]);
                    }
                    else{
                        dp[i][j][k]=max(-prices[i]+dp[i+1][0][k], dp[i+1][1][k]);
                    }
                }
            }
        }

        return dp[0][1][0];
        
    }
};