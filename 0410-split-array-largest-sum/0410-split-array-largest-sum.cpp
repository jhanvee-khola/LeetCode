class Solution {
public:
    bool possible(vector<int> nums,int maxi,int k){
        int total=0,parts=1,i=0;
        while(i<nums.size()){
            total+=nums[i];
            if(total>maxi){
                parts++;
                total=nums[i];
                if(parts>k){
                    return false;
                }
            }
            i++;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int total=0,maxi=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            maxi=max(maxi,nums[i]);
        }
        int start=maxi,end=total;
        //total is not really a possible answer for k>1 but for simplicity its taken as an upper limit
        while(start<end){
            int mid=(start+end)/2;
            if(possible(nums,mid,k)){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};