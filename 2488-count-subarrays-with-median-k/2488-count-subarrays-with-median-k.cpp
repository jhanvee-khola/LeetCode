class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int ind=find(nums.begin(),nums.end(),k)-nums.begin();
        //finding balance on right side of k
        int bal=0;
        for(int i=ind;i<nums.size();i++){
            if(nums[i]==k){
                bal+=0;
            }
            else if(nums[i]<k){
                bal-=1;
            }
            else{
                bal+=1;
            }
            count[bal]++;
        }
        int ans=0;
        bal=0;
        for(int i=ind;i>=0;i--){
            if(nums[i]==k){
                bal+=0;
            }
            else if(nums[i]<k){
                bal-=1;
            }
            else{
                bal+=1;
            }
            ans+=count[-bal]+count[-bal+1];
        }
        return ans;
    }
};