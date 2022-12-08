class Solution {
public:
    void dfs(vector<vector<int>>& adj,vector<bool> &visit,int node){
        visit[node]=true;
        for(auto it:adj[node]){
            if(!visit[it]){
                dfs(adj,visit,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int ans=0;
        vector<bool> visit(n+1,false);
        for(int i=1;i<=n;i++){
            if(!visit[i]){
                ans++;
                dfs(adj,visit,i);
            }
        }
        return ans;
    }
};