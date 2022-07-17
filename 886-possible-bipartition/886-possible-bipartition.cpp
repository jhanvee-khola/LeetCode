class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(int i=0;i<dislikes.size();i++){
            int a=dislikes[i][0];
            int b=dislikes[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> group(n+1,-1);
        for(int i=1;i<=n;i++){
            if(group[i]==-1){
                queue<int> q;
                q.push(i);
                group[i]=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto it:adj[node]){
                        if(group[it]==-1){
                            group[it]=1-group[node];
                            q.push(it);
                        }
                        else if(group[it]==group[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};