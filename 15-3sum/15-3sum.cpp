class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size()-3;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            int l=i+1,r=nums.size()-1,k=-nums[i];
            while(l<r){
                vector<int> temp;
                int d=nums[l]+nums[r];
                if(d==k){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    l++;
                    while(nums[l]==nums[l-1] && l<r){
                        l++;
                    }
                }
                else if(d<k){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};