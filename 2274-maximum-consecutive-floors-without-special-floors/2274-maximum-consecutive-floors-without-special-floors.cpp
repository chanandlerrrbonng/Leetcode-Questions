class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int n=special.size();
        int start=special[0]-bottom;
        int last=top-special[n-1];
        if(n==1) return max(start, last);
        int maxb=-1;
        for(int i=1; i<n; i++){
            maxb=max(special[i]-special[i-1]-1, maxb);
        }
        return max({maxb, start, last});
    }
};