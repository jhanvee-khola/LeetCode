class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int minFlip=0,one=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                one++;
            }
            else{
                minFlip++;
            }
            minFlip=min(minFlip,one);
        }
        return minFlip;
    }
};