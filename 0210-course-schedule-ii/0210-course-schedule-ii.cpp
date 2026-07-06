class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){

    vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> result;
        queue<int>q;
        
        
        for(auto& pre : prerequisites) {
            int scourse = pre[0];
            int fcourse = pre[1];
            adj[fcourse].push_back(scourse);
            indegree[scourse]++;
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
                result.push_back(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    result.push_back(it);
                }

            }
        }

        
        if (result.size() == numCourses) {
            return result;
        } else {
            return {};
        }
        
    }
};