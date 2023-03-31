class Solution {
public:
    void help(vector<string> &ans,string temp,int n,int o,int c){
        if(o==n && c==n){
            ans.push_back(temp);
            return;
        }
        if(o==c){
            help(ans,temp+"(",n,o+1,c);
        }
        if(o>c){
            if(o<n){
                help(ans,temp+"(",n,o+1,c);
            }
            if(c<n){
                help(ans,temp+")",n,o,c+1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";
        help(ans,temp,n,0,0);
        return ans;
    }
};