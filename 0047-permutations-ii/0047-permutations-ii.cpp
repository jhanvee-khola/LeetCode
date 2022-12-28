class Solution {
public:
    vector<vector<int>> ans;
    void recurPermute(vector<int> nums,int begin){
        if(begin>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++){
            if(i!=begin && nums[i]==nums[begin]){
                continue;
            }
            swap(nums[begin],nums[i]);
            recurPermute(nums,begin+1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        recurPermute(nums,0);
        return ans;
    }
};