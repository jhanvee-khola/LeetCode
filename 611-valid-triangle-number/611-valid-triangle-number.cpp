class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0;
        for(int i=0;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                int start=j+1,end=n-1,target=nums[i]+nums[j],mid;
                while(start<=end){
                    mid=start+(end-start)/2;
                    if(nums[mid]<target){
                        start=mid+1;
                    }
                    else{
                        end=mid-1;
                    }
                }
                ans+=(end-j);
            }
        }
        return ans;
    }
};