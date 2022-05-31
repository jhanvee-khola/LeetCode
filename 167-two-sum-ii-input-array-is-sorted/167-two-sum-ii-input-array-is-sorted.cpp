class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int l=0,r=nums.size()-1;
        while(l<r){
            int d=nums[l]+nums[r];
            if(d==target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            else if(d<target){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};