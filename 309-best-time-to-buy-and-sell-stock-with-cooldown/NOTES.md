Recursive solution
```
class Solution {
public:
int solve(vector<int>& p,int n,int i,int buy){
if(i>=n){
return 0;
}
if(buy){
int b=-p[i]+solve(p,n,i+1,0);
int nb=solve(p,n,i+1,1);
return max(b,nb);
}
int s=p[i]+solve(p,n,i+2,1);
int ns=solve(p,n,i+1,0);
return max(s,ns);
}
int maxProfit(vector<int>& prices) {
int n=prices.size();
return solve(prices,n,0,1);
}
};
```