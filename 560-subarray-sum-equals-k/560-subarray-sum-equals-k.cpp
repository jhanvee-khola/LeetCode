class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> u;
        int csum=0,ans=0;
        u.insert({0,1});
        for(int i=0;i<nums.size();i++){
            csum+=nums[i];
            if(u.find(csum)==u.end()){
                u.insert({csum,1});
            }
            else{
                u[csum]++;
            }
            if(u.find(csum-k)!=u.end()){
                if(csum-k!=csum){
                    ans+=u[csum-k];
                }
                else{
                    if(u[csum-k]!=1){
                        ans+=u[csum-k]-1;
                    }
                }
            }
        }
        return ans;
    }
};