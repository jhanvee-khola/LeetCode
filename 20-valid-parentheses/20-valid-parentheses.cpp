class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='(' || c=='{' || c=='['){
                t.push(c);
            }
            if(t.empty()){
                return false;
            }
            char x;
            if(c==')'){
                x=t.top();
                t.pop();
                if(x=='{' || x=='['){
                    return false;
                }
            }
            else if(c=='}'){
                x=t.top();
                t.pop();
                if(x=='(' || x=='['){
                    return false;
                }
            }
            else if(c==']'){
                x=t.top();
                t.pop();
                if(x=='{' || x=='('){
                    return false;
                }
            }
        }
        return t.empty();
    }
};