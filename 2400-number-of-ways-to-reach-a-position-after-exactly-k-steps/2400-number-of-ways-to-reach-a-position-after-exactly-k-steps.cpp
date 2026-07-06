class Solution {
public:
    const int MOD=1e9+7;
    int f(int curr, int start, int end, int steps, int k, vector<vector<int>>&dp){
        if (abs(curr - end) > k - steps)
            return 0;
        if(steps==k) return curr==end ? 1: 0;
        if(dp[curr-start+k][steps]!=-1) return dp[curr-start+k][steps]; 

        return dp[curr-start+k][steps]=(f(curr+1, start, end, steps+1, k, dp)+f(curr-1, start, end, steps+1, k, dp))%MOD;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(2*k+1, vector<int>(k+1, -1));
        return f(startPos, startPos, endPos, 0, k, dp)%MOD;
        
    }
};