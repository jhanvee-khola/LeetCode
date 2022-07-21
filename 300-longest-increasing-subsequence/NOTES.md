Recursive Solution
```
class Solution {
public:
int solve(vector<int> a,int n,int i,int prev){
if(i==n){
return 0;
}
int len=solve(a,n,i+1,prev);//Not-take case
if(prev==-1 || a[i]>a[prev]){
len=max(len,1+solve(a,n,i+1,i));
}
return len;
}
int lengthOfLIS(vector<int>& nums) {
int n=nums.size();
return solve(nums,n,0,-1);
}
};
```
Top-down DP Solution
```
class Solution {
public:
int dp[2501][2501];
int solve(vector<int> a,int n,int i,int prev){
if(i==n){
return 0;
}
if(dp[i][prev]!=-1){
return dp[i][prev];
}
int len=solve(a,n,i+1,prev);//Not-take case
if(prev==0 || a[i]>a[prev-1]){
len=max(len,1+solve(a,n,i+1,i+1));//Take-case
}
return dp[i][prev]=len;
}
int lengthOfLIS(vector<int>& nums) {
int n=nums.size();
memset(dp,-1,sizeof(dp));
return solve(nums,n,0,0);
}
};
```