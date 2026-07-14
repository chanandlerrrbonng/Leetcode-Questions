class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        if(intervals.size()==0) return ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            vector<int>& last=ans.back();
            if(intervals[i][0]<=last[1]){
                last[1]=max(last[1], intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};