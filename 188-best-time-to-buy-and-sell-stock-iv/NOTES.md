Recursive Solution
```
class Solution {
public:
int solve(vector<int> p,int n,int i,int buy,int cap){
if(i==n || cap==0){
return 0;
}
if(buy){
int b=-p[i]+solve(p,n,i+1,0,cap);
int nb=solve(p,n,i+1,1,cap);
return max(b,nb);
}
int s=p[i]+solve(p,n,i+1,1,cap-1);
int ns=solve(p,n,i+1,0,cap);
return max(s,ns);
}
int maxProfit(int k, vector<int>& prices) {
int n=prices.size();
return solve(prices,n,0,1,k);
}
};
```
Top-Down dp
​
​