class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        for(int i=0;i<prereq.size();i++){
            int course=prereq[i][0];
            int pre=prereq[i][1];
            adj[course].push_back(pre);
        }
        vector<int> inDegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        vector<int> temp;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            temp.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(temp.size()==n){
            reverse(temp.begin(),temp.end());
            ans=temp;
        }
        return ans;
    }
};