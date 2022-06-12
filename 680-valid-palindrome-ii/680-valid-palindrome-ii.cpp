class Solution {
public:
    bool check(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start=0,end=s.length()-1;
        bool ans=true;
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            }
            else{
                bool op1=check(s,start+1,end);
                bool op2=check(s,start,end-1);
                
                return op1||op2;
            }
        }
        return true;
    }
};