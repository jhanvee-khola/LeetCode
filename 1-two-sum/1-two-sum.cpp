class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans={0,0};
        for(int i=0;i<nums.size();i++){
            m.insert(make_pair(nums[i],i));
        }
        for(int i=0;i<nums.size();i++){
            unordered_map<int,int>:: iterator itr=m.find(target-nums[i]);
            if(itr!=m.end() && itr->second!=i){
                ans[0]=i;
                ans[1]=itr->second;
                break;
            }
        }
        return ans;
    }
};