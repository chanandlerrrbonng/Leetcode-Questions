class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>prevrow=matrix[0];
        vector<int>thisrow(m, INT_MAX);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int left=INT_MAX, right=INT_MAX;
                if(j>0) left=prevrow[j-1];
                int middle=prevrow[j];
                if(j<m-1) right=prevrow[j+1];
                thisrow[j]=matrix[i][j]+min({left, middle, right});
            }
            prevrow=thisrow;
        }
        return *min_element(prevrow.begin(), prevrow.end());
    }
};