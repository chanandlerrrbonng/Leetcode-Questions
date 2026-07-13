class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        string l=to_string(low);
        string h=to_string(high);
        vector<int>ans;
        for(int i=l.length(); i<=h.length(); i++){
            for(int j=0; j<=9-i; j++){
                int num=stoi(s.substr(j, i));
                if(num>=low && num<=high) ans.push_back(num);
            }
        }
        return ans;
    }
};