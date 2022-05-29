class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> u;
        int ans=0,csum=0;
        u.insert({0,1});
        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
            int r=csum%k;
            if(r<0){
                r+=k;
            }
            if(u.find(r)==u.end()){
                u.insert({r,1});
            }
            else{
                ans+=u[r];
                u[r]++;
            }
        }
        return ans;
    }
};