**DFS Solution**
class Solution {
public:
bool dfsTravel(vector<vector<int>> adj,vector<int> &visit,stack<int> &s,int node){
if(visit[node]==1){
return false;
}
if(visit[node]==2){
return true;
}
visit[node]=1;
for(auto it:adj[node]){
if(!dfsTravel(adj,visit,s,it)){
return false;
}
}
visit[node]=2;
s.push(node);
return true;
}
vector<int> findOrder(int n, vector<vector<int>>& prereq) {
vector<vector<int>> adj(n);
for(int i=0;i<prereq.size();i++){
int course=prereq[i][0];
int pre=prereq[i][1];
adj[course].push_back(pre);
}
vector<int> visit(n+1,0);
stack<int> topo;
vector<int> ans;
for(int i=0;i<n;i++){
if(!dfsTravel(adj,visit,topo,i)){
return ans;
}
}
while(!topo.empty()){
int course=topo.top();
topo.pop();
ans.push_back(course);
}
reverse(ans.begin(),ans.end());
return ans;
}
};
​