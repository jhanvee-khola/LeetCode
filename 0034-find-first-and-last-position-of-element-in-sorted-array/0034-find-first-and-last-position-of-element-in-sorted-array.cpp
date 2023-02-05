class Solution {
public:
    int lowerBound(vector<int> nums,int target){
        int start=0,end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return start;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=lowerBound(nums,target);
        int r=lowerBound(nums,target+1)-1;
        if(l<nums.size() && nums[l]==target){
            return {l,r};
        }
        return {-1,-1};
    }
};