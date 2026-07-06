class Solution {
public:
    int f(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>&dp){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(nums1[idx1]==nums2[idx2]) return dp[idx1][idx2]=1+f(idx1-1, idx2-1, nums1, nums2, dp);
        else return dp[idx1][idx2]=max(f(idx1-1, idx2, nums1, nums2, dp), f(idx1, idx2-1, nums1, nums2, dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        return f(n1-1, n2-1, nums1, nums2, dp);
        
    }
};