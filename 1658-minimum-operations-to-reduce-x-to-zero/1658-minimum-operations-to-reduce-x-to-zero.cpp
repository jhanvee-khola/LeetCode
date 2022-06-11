class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(x==0){
            return 0;
        }
        int numTotal=0;
        for(int i=0;i<nums.size();i++){
            numTotal+=nums[i];
        }
        int k=numTotal-x;
        int wstart=0,wsum=0;
        bool exist=false;
        int ans=0;
        for(int wend=0;wend<nums.size();wend++){
            wsum+=nums[wend];
            while(wstart<=wend && wsum>k){
                wsum-=nums[wstart];
                wstart++;
            }
            if(wsum==k){
                exist=true;
                ans=max(ans,wend-wstart+1);
            }
        }
        if(exist){
            return nums.size()-ans;
        }
        return -1;
    }
};