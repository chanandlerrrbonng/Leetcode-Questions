class Solution {
public:
    int f(int idx1, int idx2, string &s, string &t, vector<vector<int>>&dp){
        if(idx2<0) return 1;
        if(idx1<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s[idx1]==t[idx2]) return dp[idx1][idx2]=f(idx1-1, idx2, s, t, dp)+f(idx1-1, idx2-1, s, t, dp);
        else return dp[idx1][idx2]=f(idx1-1, idx2, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        int ans=f(n1-1, n2-1, s, t, dp);
        return dp[n1-1][n2-1];
    }
};