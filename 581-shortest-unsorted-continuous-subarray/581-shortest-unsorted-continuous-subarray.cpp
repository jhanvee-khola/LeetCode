class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left=-1,right=nums.size();
        int mini=nums[nums.size()-1],maxi=nums[0];;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<maxi){
                right=i;
            }
            else{
                maxi=nums[i];
            }
        }
        for(int i=nums.size()-2;i>=0;i--){
            if(mini<nums[i]){
                left=i;
            }
            else{
                mini=nums[i];
            }
        }
        if(left==-1){
            return 0;
        }
        return right-left+1;
    }
};