class Solution {
public:
    void dfsTravel(vector<vector<int>> &grid,int i,int j){
        grid[i][j]=-1;
        if(i+1<grid.size() && grid[i+1][j]==1){
            dfsTravel(grid,i+1,j);
        }
        if(i-1>=0 && grid[i-1][j]==1){
            dfsTravel(grid,i-1,j);
        }
        if(j+1<grid[0].size() && grid[i][j+1]==1){
            dfsTravel(grid,i,j+1);
        }
        if(j-1>=0 && grid[i][j-1]==1){
            dfsTravel(grid,i,j-1);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && grid[i][j]==1){
                    dfsTravel(grid,i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};