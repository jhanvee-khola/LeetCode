class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,int> ms,mt;
        int l=s.length();
        for(int i=0;i<l;i++){
            ms[s[i]]++;
            mt[t[i]]++;
        }
        return ms==mt;
    }
};