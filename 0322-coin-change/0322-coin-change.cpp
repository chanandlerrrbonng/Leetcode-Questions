class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        for(int i=1; i<=amount; i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=INT_MAX;
        }
        for(int i=1; i<n; i++){
            for(int amt=0; amt<=amount; amt++){
                int nottake=dp[i-1][amt];
                int take=INT_MAX;
                if(amt>=coins[i]){
                    int res=dp[i][amt-coins[i]];
                    if(res!=INT_MAX) take=1+res;
                }
                dp[i][amt]=min(take, nottake);
            }
        }
        return dp[n-1][amount]==INT_MAX? -1: dp[n-1][amount];
    }
};