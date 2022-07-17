class Solution {
public:
    void dfsTravel(vector<vector<int>> rooms,vector<bool> &visit,int node){
        visit[node]=true;
        for(auto it:rooms[node]){
            if(!visit[it]){
                dfsTravel(rooms,visit,it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visit(n,false);
        dfsTravel(rooms,visit,0);
        for(int i=0;i<n;i++){
            if(!visit[i]){
                return false;
            }
        }
        return true;
    }
};