class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),ans=INT_MIN,mini=1,maxi=1;
        for(int i=0;i<n;i++){
            int temp=max(maxi*nums[i],max(mini*nums[i],nums[i]));
            mini=min(maxi*nums[i],min(mini*nums[i],nums[i]));
            maxi=temp;
            ans=max(ans,maxi);
        }
        return ans;
    }
};