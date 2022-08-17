class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int count=0,start=0,prod=1;
        for(int end=0;end<nums.size();end++){
            prod*=nums[end];
            while(prod>=k){
                prod/=nums[start];
                start++;
            }
            count+=(end-start+1);
        }
        return count;
    }
};