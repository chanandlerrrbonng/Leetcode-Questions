class Solution {
public:
    vector<int>parent, size;

    int findparent(int node){
        if(node==parent[node]) return node;
        else return parent[node]=findparent(parent[node]);
    }
    void unionbysize(int u, int v){
        int upu=findparent(u);
        int upv=findparent(v);

        if(upu==upv) return;
        else if(size[upu]>size[upv]){
            size[upu]+=size[upv];
            parent[upv]=upu;
        }
        else{
            size[upv]+=size[upu];
            parent[upu]=upv;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    unionbysize(i, j);
                }
            }
        }
        int comp=0;
        for(int i=0; i<n; i++){
            if(parent[i]==i) comp++;
        }
        return n-comp;
    }
};