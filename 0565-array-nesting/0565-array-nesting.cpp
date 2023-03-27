class Solution {
public:
    int dfs(int curr,vector<int> &nums){
        if(nums[curr]<0){
            return 0;
        }
        if(nums[curr]==0){
            nums[curr]=-1;
            return 1+dfs(0,nums);
        }
        nums[curr]*=-1;
        return 1+dfs(abs(nums[curr]),nums);
    }
    int arrayNesting(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,dfs(i,nums));
        }
        return ans;
    }
};