class Solution {
public:
    void help(vector<vector<int>> grid,int m,int n,int empty,int &ans){
        if(m<0 || n<0 || m>=grid.size() || n>=grid[0].size() || grid[m][n]<0){
            return;
        }
        if(grid[m][n]==2){
            if(empty==0){
                ans++;
            }
            return;
        }
        grid[m][n]=-2;
        empty--;
        help(grid,m-1,n,empty,ans);
        help(grid,m,n-1,empty,ans);
        help(grid,m+1,n,empty,ans);
        help(grid,m,n+1,empty,ans);
        grid[m][n]=0;
        empty++;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=-1,n=-1,empty=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    empty++;
                }
                if(grid[i][j]==1){
                    m=i;
                    n=j;
                }
            }
        }
        int ans=0;
        help(grid,m,n,empty,ans);
        return ans;
    }
};