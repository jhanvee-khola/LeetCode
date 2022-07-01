class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        vector<string> rows(numRows,"");
        int si=0,vi=0,dir=1;
        while(si<s.length()){
            if(vi==numRows-1){
                dir=-1;
            }
            if(vi==0){
                dir=1;
            }
            rows[vi]+=s[si];
            si++;
            vi+=dir;
        }
        string ans="";
        for(int i=0;i<rows.size();i++){
            ans+=rows[i];
        }
        return ans;
    }
};