class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0, y=0;
        for(auto it: moves){
            if(it=='U'){
                x++;
            }
            if(it=='D') x--;
            if(it=='L') y--;
            if(it=='R') y++;
        }
        if(!x && !y) return true;
        return false;
    }
};