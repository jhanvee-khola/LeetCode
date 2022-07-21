Recursive Solution
Using sign to determine whether buy is possible or not
```
class Solution {
public:
int solve(vector<int> p,int i,int n,int buy){
if(i>=n || buy==2){
return 0;
}
if(buy==0 || buy==1){
int b=-p[i]+solve(p,i+1,n,-(buy+1));
int nb=solve(p,i+1,n,buy);
return max(b,nb);
}
int s=p[i]+solve(p,i+1,n,-(buy));
int ns=solve(p,i+1,n,buy);
return max(s,ns);
}
int maxProfit(vector<int>& prices) {
int n=prices.size();
return solve(prices,0,n,0);
}
};
```