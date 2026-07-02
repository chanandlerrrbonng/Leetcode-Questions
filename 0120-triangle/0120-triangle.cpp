class Solution {
public:
    int minans(int idx, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(idx==triangle.size()-1) return dp[idx][col]=triangle[idx][col];
        if(dp[idx][col]!=1e7) return dp[idx][col];
        int d=triangle[idx][col]+minans(idx+1, col, triangle, dp);
        int dg=triangle[idx][col]+minans(idx+1, col+1, triangle, dp);
        return dp[idx][col]=min(d, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int j=0;
        vector<vector<int>>dp(n, vector<int>(n, 1e7));
        return minans(j, j, triangle, dp);
        
    }
};