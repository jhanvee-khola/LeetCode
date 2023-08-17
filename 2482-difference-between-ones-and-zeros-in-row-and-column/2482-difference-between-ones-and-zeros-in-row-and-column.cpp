class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> row(grid.size());
        vector<int> col(grid[0].size());
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
            }
        }
        vector<vector<int>> diff(grid.size(),vector<int>(grid[0].size()));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                diff[i][j]=2*row[i]-grid[i].size()+2*col[j]-grid.size();
            }
        }
        return diff;
    }
};