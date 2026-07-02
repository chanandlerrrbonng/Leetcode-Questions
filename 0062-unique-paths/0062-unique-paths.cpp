class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prevrow(n, 1);
        for(int i=1; i<m; i++){
            int prevcol=1;
            for(int j=1; j<n; j++){
                prevcol=prevcol+prevrow[j];
                prevrow[j]=prevcol;
            }
        }
        return prevrow[n-1];
    }
};