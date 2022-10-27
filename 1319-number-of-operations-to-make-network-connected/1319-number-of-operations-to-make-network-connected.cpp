class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<bool> &visit,int node){
        visit[node]=true;
        for(auto it:adj[node]){
            if(!visit[it]){
                dfs(adj,visit,it);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visit(n,false);
        int comp=0;
        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(adj,visit,i);
                comp++;
            }
        }
        return comp-1;
    }
};