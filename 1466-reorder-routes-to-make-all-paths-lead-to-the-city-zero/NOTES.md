DFS - TLE
```
class Solution {
public:
int count=0;
void dfs(vector<vector<int>> adj,vector<int>& leadsTo,int node){
if(leadsTo[node]==1){
return;
}
leadsTo[node]=0;
for(auto it:adj[node]){
if(leadsTo[it]==1){
leadsTo[node]=1;
return;
}
else{
dfs(adj,leadsTo,it);
}
}
leadsTo[node]=1;
count++;
return;
}
int minReorder(int n, vector<vector<int>>& connections) {
vector<vector<int>> adj(n);
vector<int> leadsTo(n,-1);
for(int i=0;i<n-1;i++){
int u=connections[i][0];
int v=connections[i][1];
adj[u].push_back(v);
if(v==0){
leadsTo[u]=1;
}
}
for(int i=1;i<=n-1;i++){
if(leadsTo[i]==-1){
dfs(adj,leadsTo,i);
}
}
return count;
}
};
```
DFS(2) - TLE
```
class Solution {
public:
void dfs(vector<vector<int>> adj,vector<int>& visit,int node,int &count){
visit[node]=1;
for(auto city:adj[node]){
if(!visit[abs(city)]){