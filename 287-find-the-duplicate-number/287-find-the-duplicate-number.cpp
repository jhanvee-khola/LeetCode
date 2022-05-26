class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(fast==slow){
                break;
            }
        }
        fast=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};