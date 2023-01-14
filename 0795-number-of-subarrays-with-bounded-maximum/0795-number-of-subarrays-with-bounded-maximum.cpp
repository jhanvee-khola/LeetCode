class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans=0,part=0,low=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>right){
                part=0;
            }
            else{
                part++;
                ans+=part;
            }
            if(nums[i]<left){
                low++;
                ans-=low;
            }
            else{
                low=0;
            }
        }
        return ans;
    }
};