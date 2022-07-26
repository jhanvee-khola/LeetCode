class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections){
        vector<vector<int>> adj(n),back(n);
        vector<int> visit(n,0);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            back[v].push_back(u);
        }
        queue<int> q;
        q.push(0);
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            visit[node]=1;
            for(auto city:adj[node]){
                if(!visit[city]){
                    count++;
                    q.push(city);
                }
            }
            for(auto city:back[node]){
                if(!visit[city]){
                    q.push(city);
                }
            }
        }
        return count;
    }
};