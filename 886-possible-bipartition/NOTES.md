DFS Solution
```
class Solution {
public:
bool dfsTravel(vector<vector<int>> adj,vector<int> &group,int node){
if(group[node]==-1){
group[node]=0;
}
for(auto it:adj[node]){
if(group[it]==-1){
group[it]=1-group[node];
if(!dfsTravel(adj,group,it)){
return false;
}
}
else if(group[it]==group[node]){
return false;
}
}
return true;
}
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
if(!dfsTravel(adj,group,i)){
return false;
}
}
}
return true;
}
};
```