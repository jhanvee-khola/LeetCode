class Solution {
public:
    int dp[51][51][51][51];
    int help(vector<vector<int>>& grid,int n,int i1,int j1,int i2,int j2){
        if(i1>=n || i2>=n || j1>=n || j2>=n || grid[i1][j1]==-1 || grid[i2][j2]==-1){
            return INT_MIN;
        }
        if(i1==n-1 && j1==n-1){
            return grid[i1][j1];
        }
        if(i2==n-1 && j2==n-1){
            return grid[i2][j2];
        }
        if(dp[i1][j1][i2][j2]!=-1){
            return dp[i1][j1][i2][j2];
        }
        int total;
        if(i1==i2 && j1==j2){
            total=grid[i1][j1];
        }
        else{
            total=grid[i1][j1]+grid[i2][j2];
        }
        int c1=help(grid,n,i1+1,j1,i2+1,j2);
        int c2=help(grid,n,i1+1,j1,i2,j2+1);
        int c3=help(grid,n,i1,j1+1,i2+1,j2);
        int c4=help(grid,n,i1,j1+1,i2,j2+1);
        total+=max(max(c1,c2),max(c3,c4));
        return dp[i1][j1][i2][j2]=total;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,help(grid,n,0,0,0,0));
    }
};