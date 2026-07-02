class Solution {
public:
    vector<vector<int>>dp;
    int recurse(vector<vector<int>>& matrix, int row, int col){
        if(col < 0 || col >= matrix[0].size()) return 1e9;
        if(row==matrix.size()-1) return matrix[row][col];
        if(dp[row][col]!=1e9) return dp[row][col];
        return dp[row][col]=matrix[row][col]+min({recurse(matrix, row+1, col), recurse(matrix, row+1, col-1), recurse(matrix, row+1, col+1)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        dp.assign(n, vector<int>(m, 1e9));
        int ans=INT_MAX;
        for(int i=0; i<m; i++){
            ans=min(recurse(matrix, 0, i), ans);
        }
        return ans;
        
    }
};