class Solution {
public:
    bool help(vector<int> &nums,int n,vector<int> &dp){
        if(n==0){
            return true;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        if(n>=3 && nums[n-1]==nums[n-2]+1 && nums[n-2]==nums[n-3]+1){
            if(help(nums,n-3,dp)){
                return dp[n]=true;
            }
        }
        if(n>=2 && nums[n-1]==nums[n-2]){
            if(help(nums,n-2,dp)){
                return dp[n]=true;
            }
            if(n>=3 && nums[n-2]==nums[n-3]){
                if(help(nums,n-3,dp)){
                    return dp[n]=true;
                }
            }
        }
        return dp[n]=false;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        dp[0]=1;
        return help(nums,n,dp);
    }
};