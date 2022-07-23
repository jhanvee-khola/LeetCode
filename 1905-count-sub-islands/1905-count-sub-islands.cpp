class Solution {
public:
    void dfsTravel(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,bool &b){
        if(i<0 || j<0 || i>=grid1.size() || j>=grid1[0].size()){
            return;
        }
        if(grid2[i][j]==0){
            return;
        }
        if(grid1[i][j]==0){
            b=false;
            return;
        }
        grid2[i][j]=0;
        grid1[i][j]=0;
        dfsTravel(grid1,grid2,i+1,j,b);
        dfsTravel(grid1,grid2,i-1,j,b);
        dfsTravel(grid1,grid2,i,j+1,b);
        dfsTravel(grid1,grid2,i,j-1,b);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid2.size(),n=grid2[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 && grid1[i][j]==1){
                    bool b=true;
                    dfsTravel(grid1,grid2,i,j,b);
                    if(b){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};