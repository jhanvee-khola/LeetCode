return dp[i][prev]=len;
}
int lengthOfLIS(vector<int>& nums) {
int n=nums.size();
memset(dp,-1,sizeof(dp));
return solve(nums,n,0,0);
}
};
```
Bottom-up DP
```
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
int n=nums.size();
int dp[n+1][n+1];
memset(dp,0,sizeof(dp));
for(int i=n-1;i>=0;i--){
for(int prev=i-1;prev>=-1;prev--){
int len=dp[i+1][prev+1];
if(prev==-1 || nums[i]>nums[prev]){
len=max(len,1+dp[i+1][i+1]);
}
dp[i][prev+1]=len;
}
}
return dp[0][0];
}
};
```
Space-optimized
```
class Solution {
public:
int lengthOfLIS(vector<int>& nums) {
int n=nums.size();
vector<int> after(n+1,0);
vector<int> curr(n+1,0);
for(int i=n-1;i>=0;i--){
for(int prev=i-1;prev>=-1;prev--){
int len=after[prev+1];
if(prev==-1 || nums[i]>nums[prev]){
len=max(len,1+after[i+1]);
}
curr[prev+1]=len;
}
after=curr;
}
return after[0];
}
};
```
Bottom-up DP