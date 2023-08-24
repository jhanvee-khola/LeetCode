class Solution {
public:
    int help(vector<int> nums,int target,int len,vector<unordered_map<int,int>> &dp){
        if(len==0 && target==0){
            return 1;
        }
        if(len==0){
            return 0;
        }
        auto i=dp[len].find(target);
        if(i!=dp[len].end()){
            return i->second;
        }
        return dp[len][target]=help(nums,target-nums[len-1],len-1,dp)+help(nums,target,len-1,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //              sum(P)-sum(N)=target
        //sum(P)+sum(N)+sum(P)-sum(N)=target+sum(P)+sum(N)
        //2*sum(P)=target+sum(nums)
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum<target || (target+sum)%2){
            return 0;
        }
        vector<unordered_map<int,int>> dp(n+1);
        return help(nums,(target+sum)/2,n,dp);
    }
};