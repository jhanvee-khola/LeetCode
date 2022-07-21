};
```
Bottom-up DP
```
class Solution {
public:
int maxProfit(int k, vector<int>& prices) {
int n=prices.size();
vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
for(int i=n-1;i>=0;i--){
for(int buy=0;buy<=1;buy++){
for(int cap=1;cap<=k;cap++){
if(buy){
int b=-prices[i]+dp[i+1][0][cap];
int nb=dp[i+1][1][cap];
dp[i][buy][cap]=max(b,nb);
}
else{
int s=prices[i]+dp[i+1][1][cap-1];
int ns=dp[i+1][0][cap];
dp[i][buy][cap]=max(s,ns);
}
}
}
}
return dp[0][1][k];
}
};
```
​