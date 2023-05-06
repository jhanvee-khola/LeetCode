class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.length()-1;
        char c;
        while(i<j && s[i]==s[j]){
            c=s[i];
            while(i<j && s[i]==c){
                i++;
            }
            while(i<j && s[j]==c){
                j--;
            }
        }
        if(s[i]==c){
            return 0;
        }
        return j-i+1;
    }
};