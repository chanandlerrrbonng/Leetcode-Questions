class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);

        int prev2=0;
        int prev=nums[0];
        for(int i=1; i<n-1; i++){
            int take=prev2+nums[i];
            int nottake=prev;
            int amt=max(take, nottake);
            prev2=prev;
            prev=amt;
        }
        int ans1=prev;
        prev2=0;
        prev=nums[1];
        for(int i=2; i<n; i++){
            int take=prev2+nums[i];
            int nottake=prev;
            int amt=max(take, nottake);
            prev2=prev;
            prev=amt;
        }
        int ans2=prev;
        return max(ans1, ans2);
    }
};