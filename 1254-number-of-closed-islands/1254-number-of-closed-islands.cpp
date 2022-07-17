class Solution {
public:
    int dfsTravel(vector<vector<int>> &grid,int i,int j,bool &contact){
        if((i==0 || i==grid.size()-1) && grid[i][j]==0){
            contact=false;
            return 0;
        }
        if((j==0 || j==grid[0].size()-1) && grid[i][j]==0){
            contact=false;
            return 0;
        }
        if(grid[i][j]==1){
            return 0;
        }
        grid[i][j]=1;
        dfsTravel(grid,i+1,j,contact);
        dfsTravel(grid,i-1,j,contact);
        dfsTravel(grid,i,j+1,contact);
        dfsTravel(grid,i,j-1,contact);
        if(contact){
            return 1;
        }
        return 0;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int count=0;
        for(int i=1;i<grid.size()-1;i++){
            for(int j=1;j<grid[0].size()-1;j++){
                bool b=true;
                count+=dfsTravel(grid,i,j,b);
            }
        }
        return count;
    }
};