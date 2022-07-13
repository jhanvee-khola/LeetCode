class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        if(m<n){
            return false;
        }
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++){
            freq[s1[i]]++;
        }
        int start=0,match=0;
        for(int end=0;end<m;end++){
            if(freq.find(s2[end])!=freq.end()){
                freq[s2[end]]--;
                if(freq[s2[end]]==0){
                    match++;
                }
            }
            if(match==freq.size()){
                return true;
            }
            if(end>=n-1){
                if(freq.find(s2[start])!=freq.end()){
                    if(freq[s2[start]]==0){
                        match--;
                    }
                    freq[s2[start]]++;
                }
                start++;
            }
        }
        return false;
    }
};