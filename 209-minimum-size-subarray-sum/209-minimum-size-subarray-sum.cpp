class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int csum=0,minl=INT_MAX,start=0;
        for(int end=0;end<nums.size();end++){
            csum+=nums[end];
            while(csum>=target){
                minl=min(minl,end-start+1);
                csum-=nums[start];
                start++;
            }
        }
        return minl==INT_MAX ? 0:minl;
    }
};