class Solution {
public:
    int removePalindromeSub(string s) {
        int n=s.length();
        bool b=true;
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i]){
                b=false;
                break;
            }
        }
        if(b){
            return 1;
        }
        return 2;
    }
};