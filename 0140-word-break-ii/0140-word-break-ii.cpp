class Solution {
public:
    void help(vector<string> &ans,string temp,string s,unordered_map<string,int> m,int ind){
        if(ind==s.length()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        string curr="";
        for(int i=ind;i<s.length();i++){
            curr+=s[i];
            if(m.find(curr)!=m.end()){
                help(ans,temp+curr+" ",s,m,i+1);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_map<string,int> m;
        for(auto i:wordDict){
            m[i]++;
        }
        string temp="";
        help(ans,temp,s,m,0);
        return ans;
    }
};