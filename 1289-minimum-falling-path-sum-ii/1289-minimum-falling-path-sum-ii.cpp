class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>prevrow=matrix[0];
        vector<int>thisrow(m, INT_MAX);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int prevmin=INT_MAX;
                for(int k=0; k<m; k++){
                    if(k!=j) prevmin=min(prevmin, prevrow[k]);
                }
                thisrow[j]=matrix[i][j]+prevmin;
            }
            prevrow=thisrow;
        }
        return *min_element(prevrow.begin(), prevrow.end());
    }
};