class Solution {
public:
    int dfsTravel(int i,int j,vector<vector<char>>& grid){
        if(i<0||i>grid.size()-1||j<0||j>grid[0].size()-1){
            return 0;
        }
        if(grid[i][j]=='0'){
            return 0;
        }
        grid[i][j]='0';
        dfsTravel(i+1,j,grid);
        dfsTravel(i-1,j,grid);
        dfsTravel(i,j+1,grid);
        dfsTravel(i,j-1,grid);
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count+=dfsTravel(i,j,grid);
                }
            }
        }
        return count;
    }
};