class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n=g.size();
        int m=s.size();
        if(n==0 || m==0) return 0;
        int cnt=0;
        int left=0;
        for(int i=0; i<n; i++){
            while(left<m && s[left]<g[i]){
                left++;
            }
            if( left<m && s[left]>=g[i]){
                cnt++;
                left++;
                continue;
            }
            
        }
        return cnt;
    }
};