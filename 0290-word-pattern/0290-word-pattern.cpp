class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int> pdict;
        unordered_map<string,int> sdict;
        istringstream ins(s);
        int i=0,n=pattern.size();
        for(string str;ins>>str;i++){
            if(i==n || pdict[pattern[i]]!=sdict[str]){
                return false;
            }
            pdict[pattern[i]]=sdict[str]=i+1;
        }
        return i==n;
    }
};