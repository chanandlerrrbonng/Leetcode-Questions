class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==1) return max(nums[0], nums[1]);

        int prev2=0;
        int prev=nums[0];
        for(int i=1; i<n; i++){
            int take=prev2+nums[i];
            int nottake=prev;
            int amt=max(take, nottake);
            prev2=prev;
            prev=amt;
        }
        return prev;
    }
};