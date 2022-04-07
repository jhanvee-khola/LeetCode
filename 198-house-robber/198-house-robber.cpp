class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int a=0,b=nums[0];
        for(int i=1;i<n;i++){
            int c=max(b,nums[i]+a);
            a=b;
            b=c;
        }
        return b;
    }
};