class Solution {
public:
    bool dfsTravel(vector<vector<int>> &graph,vector<int> &cycle,int node){
        if(cycle[node]){
            return cycle[node]==1;
        }
        cycle[node]=-1;
        for(auto it:graph[node]){
            if(!dfsTravel(graph,cycle,it)){
                return false;
            }
        }
        cycle[node]=1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> cycle(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dfsTravel(graph,cycle,i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};