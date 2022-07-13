class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.length(),m=p.length();
        unordered_map<char,int> freq;
        for(int i=0;i<m;i++){
            freq[p[i]]++;
        }
        vector<int> ans;
        int start=0,match=0;
        for(int end=0;end<n;end++){
            if(freq.find(s[end])!=freq.end()){
                freq[s[end]]--;
                if(freq[s[end]]==0){
                    match++;
                }
            }
            if(match==freq.size()){
                ans.push_back(start);
            }
            if(end>=m-1){
                if(freq.find(s[start])!=freq.end()){
                    if(freq[s[start]]==0){
                        match--;
                    }
                    freq[s[start]]++;
                }
                start++;
            }
        }
        return ans;
    }
};