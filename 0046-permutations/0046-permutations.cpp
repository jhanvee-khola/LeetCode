class Solution {
public:
    vector<vector<int>> ans;
    void recurrPermuate(vector<int> &nums,int begin){
        if(begin>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            swap(nums[begin],nums[i]);
            recurrPermuate(nums,begin+1);
            swap(nums[begin],nums[i]);//backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {   
        recurrPermuate(nums,0);
        return ans;
    }
};