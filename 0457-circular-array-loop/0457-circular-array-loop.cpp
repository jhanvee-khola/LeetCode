class Solution {
public:
    int next(int i,vector<int> nums){
        int n=nums.size();
        if(i+nums[i]>=0){
            return (i+nums[i])%n;
        }
        return n+((i+nums[i])%n);
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return false;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                continue;
            }
            int slow=i,fast=next(i,nums);
            while(nums[i]*nums[fast]>0 && nums[i]*nums[next(fast,nums)]>0){
                if(slow==fast){
                    if(slow==next(slow,nums)){
                        break;//1 member cycle
                    }
                    return true;
                }
                slow=next(slow,nums);
                fast=next(next(fast,nums),nums);
            }
            int j=i;
            int val=nums[i];
            while(nums[j]*val>0){
                int newJ=next(j,nums);
                nums[j]=0;
                j=newJ;
            }
        }
        return false;
    }
};