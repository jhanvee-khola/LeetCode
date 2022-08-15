class Solution {
public:
    vector<vector<int>> ans;
    void dfsVisit(vector<vector<int>> &adj,vector<int> &low,vector<int> &disc,vector<bool> &visit,int node,int parent,int &time){
        visit[node]=true;
        disc[node]=time;
        low[node]=time;
        time++;
        for(auto it:adj[node]){
            if(it==parent){
                continue;
            }
            if(!visit[it]){
                dfsVisit(adj,low,disc,visit,it,node,time);
                low[node]=min(low[node],low[it]);
                //check if bridge
                if(low[it]>disc[node]){
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(it);
                    ans.push_back(temp);
                }
            }
            else{
                //back-edge
                low[node]=min(low[node],disc[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> low(n,-1);
        vector<int> disc(n,-1);
        vector<bool> visit(n,false);
        int parent=-1,time=0;
        dfsVisit(adj,low,disc,visit,0,parent,time);
        return ans;
    }
};