class Solution {
    public int tribonacci(int n) {
        int prev3=0, prev2=1, prev=1;
        if(n==0) return prev3;
        if(n==1 || n==2) return prev2;
        int ans=0;
        for(int i=3; i<=n; i++){
            ans=prev+prev2+prev3;
            prev3=prev2;
            prev2=prev;
            prev=ans;
        }
        return ans;
    }
}