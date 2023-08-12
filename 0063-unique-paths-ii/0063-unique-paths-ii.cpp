class Solution {
public:
    int help(vector<vector<int>> grid,int m,int n,vector<vector<int>> &dp){
        if(m==0 && n==0){
            return 1;
        }
        int ans=0;
        if(m-1>=0 && grid[m-1][n]!=1){
            if(dp[m-1][n]!=-1){
                ans+=dp[m-1][n];
            }
            else{
                ans+=help(grid,m-1,n,dp);
            }
        }
        if(n-1>=0 && grid[m][n-1]!=1){
            if(dp[m][n-1]!=-1){
                ans+=dp[m][n-1];
            }
            else{
                ans+=help(grid,m,n-1,dp);
            }
        }
        return dp[m][n]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        return help(obstacleGrid,m-1,n-1,dp);
    }
};