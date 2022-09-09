class Solution {
public:
    bool canSplit(vector<int> nums,int maxi,int m){
        int total=0,count=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            if(total>maxi){
                count++;
                total=nums[i];
            }
        }
        return count+1<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int l=0,r=0;
        for(int i=0;i<nums.size();i++){
            l=max(l,nums[i]);
            r+=nums[i];
        }
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canSplit(nums,mid,m)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};