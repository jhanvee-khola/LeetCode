class Solution {
public:
    void getPath(string src,string dest,map<string,vector<pair<string,double>>> adj,double &val,map<string,int> &visit,bool &found){
        visit[src]=1;
        if(found){
            return;
        }
        for(auto it:adj[src]){
            string child=it.first;
            double temp=it.second;
            if(!visit[child]){
                val*=temp;
                if(child==dest){
                    found=true;
                    return;
                }
                getPath(child,dest,adj,val,visit,found);
                if(found){
                    return;
                }
                else{
                    val/=temp;
                }
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            adj[u].push_back({v,values[i]});
            adj[v].push_back({u,1.0/values[i]});
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            string src=queries[i][0];
            string dest=queries[i][1];
            if(adj.find(src)!=adj.end() && adj.find(dest)!=adj.end()){
                double val=1.0;
                bool found=false;
                map<string,int> visit;
                if(src==dest){
                    found=true;
                }
                else{
                    getPath(src,dest,adj,val,visit,found);
                }
                
                if(found){
                    ans.push_back(val);
                }
                else{
                    ans.push_back(-1.0);
                }
            }
            else{
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};