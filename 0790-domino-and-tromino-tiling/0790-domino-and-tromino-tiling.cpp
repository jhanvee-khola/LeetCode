class Solution {
public:
    int MOD=1000000007;
    long help(int n,int i,bool gap,vector<vector<int>> &dp){
        if(i>n){
            return 0;
        }
        if(i==n){
            return !gap;
        }
        if(dp[i][gap]!=-1){
            return dp[i][gap];
        }
        if(gap){
            return dp[i][gap]=(help(n,i+1,false,dp)+help(n,i+1,true,dp))%MOD;
        }
        return dp[i][gap]=(help(n,i+1,false,dp)+help(n,i+2,false,dp)+2*help(n,i+2,true,dp))%MOD;
    }
    int numTilings(int n) {
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return help(n,0,false,dp);
    }
};