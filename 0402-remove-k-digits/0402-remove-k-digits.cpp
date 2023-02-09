class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k){
            return "0";
        }
        stack<char> s;
        for(int i=0;i<num.length();i++){
            while(k && !s.empty() && s.top()>num[i]){
                s.pop();
                k--;
            }
            if(s.size()==0 && num[i]=='0'){
                continue;
            }
            s.push(num[i]);
        }
        while(k && !s.empty()){
            k--;
            s.pop();
        }
        string ans="";
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.length()==0){
            return "0";
        }
        return ans;
    }
};