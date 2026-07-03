class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int m=trainers.size();
        int n=players.size();
        int right=n-1, cnt=0;
        for(int i=m-1; i>=0; i--){
            while(right>=0 && players[right]>trainers[i]) right--;
            if(right>=0 && players[right]<=trainers[i]){
                right--;
                cnt++;
            }
        }
        return cnt;

    }
};