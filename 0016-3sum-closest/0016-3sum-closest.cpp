class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int csum=nums[i]+nums[l]+nums[r];
                if(csum==target){
                    return csum;
                }
                if(abs(target-csum)<abs(target-ans)){
                    ans=csum;
                }
                if(csum<target){
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