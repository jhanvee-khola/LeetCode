class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(noOverlapMax(nums,firstLen,secondLen),noOverlapMax(nums,secondLen,firstLen));
    }
    int noOverlapMax(vector<int> nums,int fLen,int sLen){
        int sum1=0,sum2=0,sum2Max=0,ans=0;
        for(int i=0;i<nums.size();i++){
            sum1+=nums[i];
            if(i>=fLen){
                sum1-=nums[i-fLen];
                sum2+=nums[i-fLen];
            }
            if(i>=fLen+sLen){
                sum2-=nums[i-fLen-sLen];
            }
            sum2Max=max(sum2Max,sum2);
            ans=max(ans,sum2Max+sum1);
        }
        return ans;
    }
};