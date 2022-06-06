class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int c1=nums[0]*nums[1]*nums[n-1];//if some are postive and some -ve
        int c2=nums[n-1]*nums[n-2]*nums[n-3];//all elements are +ve or -ve
        return max(c1,c2);
    }
};