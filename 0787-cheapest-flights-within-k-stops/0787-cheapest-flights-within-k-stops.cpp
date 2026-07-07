class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src, 0}});
        vector<int>dist(n, INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;

            if(stops>k) continue;

            for(auto iter: adj[node]){
                int dest=iter.first;
                int w=iter.second;
                if(w+cost<dist[dest] && stops<=k){
                    dist[dest]=w+cost;
                    q.push({stops+1, {dest, dist[dest]}});
                }
            }
        }
        return dist[dst]==INT_MAX? -1: dist[dst];
    }
};