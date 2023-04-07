class Solution {
public:
    int scoreOfParentheses(string s) {
        char prev='(';
        int ans=0,depth=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                depth++;
            }
            else{
                depth--;
                if(prev=='('){
                    ans+=pow(2,depth);
                }
            }
            prev=s[i];
        }
        return ans;
    }
};