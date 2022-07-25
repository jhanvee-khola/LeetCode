class Solution {
public:  
    static bool compare(string s,string t){
        return s.length()<t.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        unordered_map<string,int> dp;
        int ans=1; 
        for(auto word:words) {
            dp[word]=1; 
            for(int i=0;i<word.length();i++) {
                string pred= word.substr(0,i) + word.substr(i+1); 
                if(dp.find(pred)!=dp.end() && dp[pred]+1>dp[word]) {
                    dp[word]=dp[pred]+1; 
                }
            }
            ans=max(ans, dp[word]);
        }
        return ans;  
    }
};