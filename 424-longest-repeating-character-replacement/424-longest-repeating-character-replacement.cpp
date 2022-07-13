class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int start=0,ans=0,maxCount=0;
        unordered_map<char,int> freq;
        for(int end=0;end<n;end++){
            freq[s[end]]++;
            maxCount=max(maxCount,freq[s[end]]);
            if(end-start+1-maxCount>k){
                freq[s[start]]--;
                start++;
            }
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};