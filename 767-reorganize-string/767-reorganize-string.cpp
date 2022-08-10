class Solution {
public:
    string reorganizeString(string s) {
        int freq[26]={0};
        int maxFreq=0;
        for(auto c:s){
            freq[c-'a']++;
            if(freq[c-'a']>freq[maxFreq]){
                maxFreq=c-'a';
            }
        }
        if(2*freq[maxFreq]-1>s.length()){
            return "";
        }
        int i=0;
        while(freq[maxFreq]){
            s[i]='a'+maxFreq;
            i+=2;
            freq[maxFreq]--;
        }
        for(int j=0;j<26;j++){
            while(freq[j]){
                if(i>s.length()-1){
                    i=1;
                }
                s[i]='a'+j;
                freq[j]--;
                i+=2;
            }
        }
        return s;
    }
};