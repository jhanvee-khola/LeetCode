class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int maxSeq=0;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                int count=0;
                int curr=nums[i];
                while(s.find(curr)!=s.end()){
                    count++;
                    curr++;
                }
                maxSeq= max(maxSeq,count);
            }
        }
        return maxSeq;
    }
};