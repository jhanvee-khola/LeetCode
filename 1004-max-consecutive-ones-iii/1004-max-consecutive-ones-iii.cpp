class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0,ans=0,oneCount=0;
        int n=nums.size();
        for(int end=0;end<n;end++){
            if(nums[end]==1){
                oneCount++;
            }
            if(end-start+1-oneCount>k){
                if(nums[start]==1){
                    oneCount--;
                }
                start++;
            }
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};