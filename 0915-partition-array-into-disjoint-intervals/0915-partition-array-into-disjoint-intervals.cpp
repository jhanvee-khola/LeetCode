class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int leftMax,globalMax,part=0;
        leftMax=globalMax=nums[0];
        for(int i=1;i<nums.size();i++){
            globalMax=max(globalMax,nums[i]);
            if(nums[i]<leftMax){
                leftMax=globalMax;
                part=i;
            }
        }
        return part+1;
    }
};