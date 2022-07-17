class Solution {
public:
    void dfsTravel(vector<vector<int>>& grid,int i,int j,int &area){
        if(i<0||i>grid.size()-1||j<0||j>grid[0].size()-1){
            return;
        }
        if(grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        area+=1;
        dfsTravel(grid,i+1,j,area);
        dfsTravel(grid,i-1,j,area);
        dfsTravel(grid,i,j+1,area);
        dfsTravel(grid,i,j-1,area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int area=0;
                    dfsTravel(grid,i,j,area);
                    ans=max(ans,area);
                }
            }
        }
        return ans;
    }
};