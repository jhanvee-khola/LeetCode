class Solution {
public:
    int MOD=1000000007;
    vector<int> dir={-2,-1,2,1,-2,1,2,-1,-2};
    long help(int i,int j,int n,vector<vector<vector<int>>> &dp){
        if(i<0 || j<0 || i>=4 || j>=3){
            return 0;
        }
        if(i==3 && j!=1){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[i][j][n]!=-1){
            return dp[i][j][n];
        }
        long ans=0;
        for(int d=0;d<8;d++){
            int x=i+dir[d];
            int y=j+dir[d+1];
            ans+=help(x,y,n-1,dp)%MOD;
        }
        return dp[i][j][n]=ans%MOD;
    }
    int knightDialer(int n) {
        int ans=0;
        vector<vector<vector<int>>> dp(4,vector<vector<int>>(3,vector<int>(n+1,-1)));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                ans=(ans+help(i,j,n,dp))%MOD;
            }
        }
        return ans;
    }
};