class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> dpBefore(n,1);
        vector<int> dpAfter(n,1);
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i]){
                    dpBefore[i]=max(dpBefore[i],1+dpBefore[prev]);
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int ahead=n-1;ahead>i;ahead--){
                if(nums[ahead]<nums[i]){
                    dpAfter[i]=max(dpAfter[i],1+dpAfter[ahead]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(dpBefore[i]>1 && dpAfter[i]>1){
                int d=dpBefore[i]+dpAfter[i]-1;
                ans=max(ans,d);
            }
        }
        return n-ans;
    }
};