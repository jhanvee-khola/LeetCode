class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i;
        }
        int maxi=0,prev=-1;
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            maxi=max(maxi,m[s[i]]);
            if(maxi==i){
                ans.push_back(maxi-prev);
                prev=maxi;
            }
        }
        return ans;
    }
};