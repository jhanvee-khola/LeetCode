class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> ans=grid;
        while(k--){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(j==n-1){
                        if(i==m-1){
                            ans[0][0]=grid[i][j];
                        }
                        else{
                            ans[i+1][0]=grid[i][j];
                        }
                    }
                    else{
                        ans[i][j+1]=grid[i][j];
                    }
                }
            }
            grid=ans;
        }
        return ans;
    }
};