class Solution {
public:
    bool checkPal(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void help(vector<vector<string>> &ans,vector<string> temp,string s,int ind){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(checkPal(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                help(ans,temp,s,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        help(ans,temp,s,0);
        return ans;
    }
};