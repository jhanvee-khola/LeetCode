class Solution {
public:
    int help(vector<vector<int>> grid,int i,int j,vector<vector<int>> &dp){
        int m=grid.size(),n=grid[0].size();
        if(i==m-1 && j==n-1){
            if(grid[i][j]<=0){
                return -grid[i][j]+1;
            }
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int c1=INT_MAX,c2=INT_MAX;
        if(i+1<m){
            c1=help(grid,i+1,j,dp);
        }
        if(j+1<n){
            c2=help(grid,i,j+1,dp);
        }
        int ans=min(c1,c2)-grid[i][j];
        if(ans>0){
            return dp[i][j]=ans;
        }
        return dp[i][j]=1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return help(dungeon,0,0,dp);
    }
};