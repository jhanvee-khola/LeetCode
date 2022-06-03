class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string ans="1";
        n--;
        while(n--){
            string temp="";
            char curr=ans[0];
            int k=1;
            for(int i=1;i<ans.length();i++){
                if(ans[i]==ans[i-1]){
                    k++;
                }
                else{
                    temp+=to_string(k);
                    temp+=curr;
                    k=1;
                    curr=ans[i];
                }
            } 
            temp+=to_string(k);
            temp+=curr;
            ans=temp;
        }
        return ans;
    }
};