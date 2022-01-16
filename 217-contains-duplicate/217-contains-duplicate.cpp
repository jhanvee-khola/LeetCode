class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> u;
        for(int i=0;i<nums.size();i++){
            if(u.find(nums[i])==u.end()){
                u.insert(make_pair(nums[i],i));
            }
            else{
                return true;
            }
        }
        return false;
    }
};