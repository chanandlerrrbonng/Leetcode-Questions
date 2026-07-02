class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        if(o.empty() || o[0].empty()) return 0;
        int n=o.size();
        int m=o[0].size();
        if(o[0][0] == 1 || o[n-1][m-1] == 1) return 0;
        vector<vector<int>>dp(n, vector<int>(m, 0));
        dp[0][0]=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 && j==0) continue;
                if(o[i][j]==1) {dp[i][j]=0; continue;}
                if(i>0 && j>0) dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else if(i>0) dp[i][j]=dp[i-1][j];
                else if(j>0) dp[i][j]=dp[i][j-1];                
            }
        }
        return dp[n-1][m-1];
    }
};