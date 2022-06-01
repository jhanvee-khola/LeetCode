class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                if(j!=i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int l=j+1,r=nums.size()-1,k=target-(nums[i]+nums[j]);
                while(l<r){
                    vector<int> temp;
                    int d=nums[l]+nums[r];
                    if(d<k){
                        l++;
                    }
                    else if(d>k){
                        r--;
                    }
                    else{
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        
                        ans.push_back(temp);
                        l++;
                        while(nums[l]==nums[l-1] && l<r){
                            l++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};