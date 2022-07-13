class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(),m=t.length();
        unordered_map<char,int> freq;
        for(int i=0;i<m;i++){
            freq[t[i]]++;
        }
        int start=0,end,match=0,minLength=INT_MAX,ansStart=0;
        for(end=0;end<n;end++){
            if(freq.find(s[end])!=freq.end()){
                freq[s[end]]--;
                if(freq[s[end]]>=0){
                    match++;
                }
            }
            while(match==m){
                if(end-start+1<minLength){
                    minLength=end-start+1;
                    ansStart=start;
                }
                if(freq.find(s[start])!=freq.end()){
                    if(freq[s[start]]==0){
                        match--;
                    }
                    freq[s[start]]++;
                }
                start++;
            }
        }
        if(minLength>n){
            return "";
        }
        string ans="";
        for(int i=ansStart;i<ansStart+minLength;i++){
            ans+=s[i];
        }
        return ans;
    }
};