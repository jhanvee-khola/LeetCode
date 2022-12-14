class Solution {
public:
    void dfs(vector<vector<int>> &adj,int node,int parent,vector<int> &count,vector<int> &ans){
        for(auto it:adj[node]){
            if(it!=parent){
                dfs(adj,it,node,count,ans);
                count[node]+=count[it];
                ans[node]+=ans[it]+count[it];
            }
        }
    }
     void dfs2(vector<vector<int>> &adj,int node,int parent,vector<int> &count,vector<int> &ans){
         for(auto it:adj[node]){
             if(it!=parent){
                 ans[it]=ans[node]-count[it]+(adj.size()-count[it]);
                 dfs2(adj,it,node,count,ans);
             }
         }
     }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(n,0);
        vector<int> count(n,1);
        dfs(adj,0,-1,count,ans);
        dfs2(adj,0,-1,count,ans);
        return ans;
    }
};