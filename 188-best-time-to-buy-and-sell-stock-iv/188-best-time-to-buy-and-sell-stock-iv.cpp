class Solution {
public:
    int dp[1001][2][101];
    int solve(vector<int> p,int n,int i,int buy,int cap){
        if(i==n || cap==0){
            return 0;
        }
        if(dp[i][buy][cap]!=-1){
            return dp[i][buy][cap];
        }
        if(buy){
            int b=-p[i]+solve(p,n,i+1,0,cap);
            int nb=solve(p,n,i+1,1,cap);
            return dp[i][buy][cap]=max(b,nb);
        }
        int s=p[i]+solve(p,n,i+1,1,cap-1);
        int ns=solve(p,n,i+1,0,cap);
        return dp[i][buy][cap]=max(s,ns);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(prices,n,0,1,k);
    }
};