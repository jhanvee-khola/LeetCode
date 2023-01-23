class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        if(nums.size()<3){
            return 0;
        }
        unordered_map<int,long> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        long ans=0;
        int MOD=1000000007;
        for(auto i:freq){
            for(auto j:freq){
                int a=i.first,b=j.first,c=target-a-b;
                if(freq.find(c)==freq.end()){
                    continue;
                }
                if(a==b && b==c){
                    ans+=freq[a]*(freq[a]-1)*(freq[a]-2)/6;
                }
                else if(a==b && b!=c){
                    ans+=freq[a]*(freq[a]-1)/2*freq[c];
                }
                else if(a<b && b<c){
                    ans+=freq[a]*freq[b]*freq[c];
                }
            }
        }
        return ans%MOD;
    }
};