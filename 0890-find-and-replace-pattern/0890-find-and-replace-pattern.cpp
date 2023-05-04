class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            unordered_map<char,char> sm;
            unordered_map<char,char> pm;
            bool flag=true;
            for(int j=0;j<s.length();j++){
                if(pm.find(p[j])==pm.end() && sm.find(s[j])==sm.end()){
                    pm[p[j]]=s[j];
                    sm[s[j]]=p[j];
                }
                else if(pm.find(p[j])!=pm.end() && sm.find(s[j])!=sm.end()){
                    if(pm[p[j]]==s[j] && sm[s[j]]==p[j]){
                        continue;
                    }
                    else{
                        flag=false;
                        break;
                    }
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(s);
            }
        }
        return ans;
    }
};