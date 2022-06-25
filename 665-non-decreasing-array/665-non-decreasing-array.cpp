class Solution {
public:
    bool isIncreasing(vector<int>& nums){
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                return false;
            }
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                if(i==0){
                    nums[i]=nums[i+1];
                    return isIncreasing(nums);
                }
                else{
                    // if(nums[i]>nums[i+2]){
                    //     return false;
                    // }
                    int temp=nums[i+1];
                    nums[i+1]=nums[i];
                    bool b1=isIncreasing(nums);
                    nums[i]=temp;
                    nums[i+1]=temp;
                    bool b2=isIncreasing(nums);
                    
                    return b1||b2;
                }
            }
        }
        return true;
    }
};