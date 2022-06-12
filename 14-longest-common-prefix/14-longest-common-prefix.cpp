class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        string ans="";
        int i=0;
        bool b=true;
        while(b){
            if(i>=strs[0].length()){
                break;
            }
            char c=strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(i>=strs[j].length()){
                    b=false;
                    break;
                }
                if(strs[j][i]!=c){
                    b=false;
                    break;
                }
            }
            if(b){
                ans+=c;
                i++;
            }
        }
        return ans;
    }
};