class Solution {
public:
    bool check(vector<int> nums,int x,int limit){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=(nums[i]-1)/x+1;
        }
        return ans<=limit;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        while(l<r){
            int mid=(l+r)/2;
            if(check(nums,mid,threshold)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};