class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top().second<nums[i]){
                ans[s.top().first]=nums[i];
                s.pop();
            }
            s.push({i,nums[i]});
        }
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top().second<nums[i]){
                ans[s.top().first]=nums[i];
                s.pop();
            }
            s.push({i,nums[i]});
        }
        return ans;
    }
};