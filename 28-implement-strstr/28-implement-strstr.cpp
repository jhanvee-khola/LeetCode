class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }
        int j,k=0;
        for(int i=0;i<haystack.length();i++){
            j=i;
            while(haystack[j]==needle[k] && j<haystack.length() && k<needle.length()){
                j++;
                k++;
            }
            if(j==haystack.length() && k!=needle.length()){
                return -1;
            }
            else if(k==needle.length()){
                return i;
            }
            else{
                k=0;
            }
        }
        return -1;
    }
};