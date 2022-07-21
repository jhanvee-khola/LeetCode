class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> after(n+1,0);
        vector<int> curr(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int len=after[prev+1];
                if(prev==-1 || nums[i]>nums[prev]){
                    len=max(len,1+after[i+1]);
                }
                curr[prev+1]=len;
            }
            after=curr;
        }
        return after[0];
    }
};