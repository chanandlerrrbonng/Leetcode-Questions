class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>>map=isWater;
        queue<pair<pair<int, int>, int>>q;
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        for(int i=0; i<isWater.size(); i++){
            for(int j=0; j<isWater[0].size(); j++){
                if(isWater[i][j]==1) {q.push({{i, j}, 0}); visited[i][j]=1;}
            }
        }
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, 1, 0, -1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first.first;
            int y=it.first.second;
            int d=it.second;
            if(d==0) map[x][y]=0;
            else map[x][y]=d;
            for(int i=0; i<4; i++){
                int nr=x+dr[i];
                int nc=y+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc]){
                    visited[nr][nc]=1;
                    q.push({{nr, nc}, d+1});
                }
            }
            
        }
        return map;
        
    }
};