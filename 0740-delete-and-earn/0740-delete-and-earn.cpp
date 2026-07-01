class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int prev2=0, prev1=0, curridx=-1;
        for(auto const& [key, val]: mp){
            int currearn=key*val;
            int temp=prev1;
            if(key==curridx+1){
                prev1=max(prev1, prev2+currearn);
            }
            else{
                prev1=currearn+prev1;
            }
            prev2=temp;
            curridx=key;
        }
        return prev1;
    }
};