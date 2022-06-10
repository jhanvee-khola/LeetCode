class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        bool dp[n+1];
        dp[0]=dp[1]=true;
        for(int i=2;i<=n;i++){
            bool b=false;
            for(int j=i-1;j>=1;j--){
                if(nums[j-1]>=i-j && dp[j]){
                    b=true;
                    break;
                }
            }
            dp[i]=b;
        }
        return dp[n];
    }
};