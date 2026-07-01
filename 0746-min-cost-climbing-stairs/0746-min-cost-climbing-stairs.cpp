class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==0 || n==1) return 0;
        int prev2=cost[0];
        int prev=cost[1];
        if(n<=2) return min(prev, prev2);
        for(int i=2; i<n;i++){
            int curr=cost[i]+ min(prev, prev2);
            prev2=prev;
            prev=curr;
        }
        return min(prev, prev2);
    }
};