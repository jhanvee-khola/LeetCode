class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        vector<vector<int>> adj(n);
        for(int i=0;i<prereq.size();i++){
            int course=prereq[i][0];
            int pre=prereq[i][1];
            adj[course].push_back(pre);
        }
        vector<int> inDegree(n,0);
        for(int i=0;i<n;i++){
            for(auto pre:adj[i]){
                inDegree[pre]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int course=q.front();
            q.pop();
            count++;
            for(auto it:adj[course]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(count==n){
            return true;
        }
        return false;
    }
};