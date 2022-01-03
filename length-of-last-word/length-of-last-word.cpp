class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.length()==0){
            return 0;
        }
        int i=s.length()-1;
        while(s[i]==' '){
            i--;
        }
        int c=0;
        for(;i>=0;i--){
            if(s[i]!=' '){
                c++;
            }
            else{
                break;
            }
        }
        return c;
    }
};