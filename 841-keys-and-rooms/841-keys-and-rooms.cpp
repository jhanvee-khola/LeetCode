class Solution {
public:
    void dfsTravel(vector<vector<int>> rooms,vector<bool> &key,vector<bool> &visit,int node){
        visit[node]=true;
        for(auto it:rooms[node]){
            if(!visit[it]){
                key[it]=true;
                dfsTravel(rooms,key,visit,it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> key(n,false);
        vector<bool> visit(n,false);
        key[0]=true;
        for(int i=0;i<n;i++){
            if(key[i] && !visit[i]){
                dfsTravel(rooms,key,visit,i);
            }
        }
        for(int i=0;i<n;i++){
            if(!key[i]){
                return false;
            }
        }
        return true;
    }
};