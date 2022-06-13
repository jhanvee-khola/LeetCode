class Solution {
public:
    int minPath(vector<vector<int>> &triangle,int i,int j,int n,vector<vector<int>>& dp){
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int c1=triangle[i][j]+minPath(triangle,i+1,j,n,dp);
        int c2=triangle[i][j]+minPath(triangle,i+1,j+1,n,dp);
        
        return dp[i][j]=min(c1,c2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return minPath(triangle,0,0,n,dp);
    }
};