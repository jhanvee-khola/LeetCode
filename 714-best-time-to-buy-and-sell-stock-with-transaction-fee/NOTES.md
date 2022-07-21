Top-down DP
```
class Solution {
public:
int dp[50001][2];
int solve(vector<int> p,int n,int fee,int i,int buy){
if(i==n){
return 0;
}
if(dp[i][buy]!=-1){
return dp[i][buy];
}
if(buy){
int b=-p[i]+solve(p,n,fee,i+1,0);
int nb=solve(p,n,fee,i+1,1);
return dp[i][buy]=max(b,nb);
}
int s=p[i]-fee+solve(p,n,fee,i+1,1);
int ns=solve(p,n,fee,i+1,0);
return dp[i][buy]=max(s,ns);
}
int maxProfit(vector<int>& prices, int fee) {
int n=prices.size();
memset(dp,-1,sizeof(dp));
return solve(prices,n,fee,0,1);
}
};
```