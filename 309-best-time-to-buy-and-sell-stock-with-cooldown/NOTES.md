```
Top-down DP
```
class Solution {
public:
int dp[5001][2];
int solve(vector<int>& p,int n,int i,int buy){
if(i>=n){
return 0;
}
if(dp[i][buy]!=-1){
return dp[i][buy];
}
if(buy){
int b=-p[i]+solve(p,n,i+1,0);
int nb=solve(p,n,i+1,1);
return dp[i][buy]=max(b,nb);
}
int s=p[i]+solve(p,n,i+2,1);
int ns=solve(p,n,i+1,0);
return dp[i][buy]=max(s,ns);
}
int maxProfit(vector<int>& prices) {
int n=prices.size();
memset(dp,-1,sizeof(dp));
return solve(prices,n,0,1);
}
};
```
​