class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,ans=INT_MAX,wsum=0;
        for(int end=0;end<nums.size();end++){
            wsum+=nums[end];
            while(wsum>=target){
                ans=min(ans,end-start+1);
                wsum-=nums[start];
                start++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};