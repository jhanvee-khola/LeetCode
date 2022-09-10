class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(auto it:freq){
            pq.push({it.second,it.first});
            if(pq.size()>freq.size()-k){
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};