class Solution {
public:
    int help(int n,int i,vector<vector<int>> &dp){
        if(n==0 or i==0){
            return 1;
        }
        if(dp[n][i]!=-1){
            return dp[n][i];
        }
        if(i>n){
            return dp[n][i]=help(n,i-1,dp);
        }
        return dp[n][i]=max(i*help(n-i,i,dp),help(n,i-1,dp));
    }
    int integerBreak(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return help(n,n-1,dp);
    }
};