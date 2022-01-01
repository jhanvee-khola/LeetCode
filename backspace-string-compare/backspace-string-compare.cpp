class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,t1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(s1.empty()){
                    continue;
                }
                s1.pop();
            }
            else{
                s1.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(t1.empty()){
                    continue;
                }
                t1.pop();
            }
            else{
                t1.push(t[i]);
            }
        }
        while(!s1.empty() && !t1.empty()){
            if(s1.top()!=t1.top()){
                return false;
            }
            s1.pop();
            t1.pop();
        }
        if(!s1.empty() || !t1.empty()){
            return false;
        }
        return true;
    }
};