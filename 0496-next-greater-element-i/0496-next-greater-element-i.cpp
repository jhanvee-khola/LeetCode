class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++){
            int n=nums2[i];
            while(!s.empty() && s.top()<n){
                m[s.top()]=n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            if(m.find(nums1[i])!=m.end()){
                ans.push_back(m[nums1[i]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};