class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else{
                if(temp.length()!=0){
                    words.push_back(temp);
                    temp="";
                }
            }
        }
        if(temp.length()!=0){
            words.push_back(temp);
        }
        reverse(words.begin(),words.end());
        string ans=words[0];
        for(int i=1;i<words.size();i++){
            ans+=" ";
            ans+=words[i];
        }
        return ans;
    }
};