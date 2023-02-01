class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.length();
        vector<int> ans(n,n);
        int ind=-n;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                ind=i;
            }
            ans[i]=i-ind;
        }
        for(int i=ind-1;i>=0;i--){
            if(s[i]==c){
                ind=i;
            }
            ans[i]=min(ans[i],ind-i);
        }
        return ans;
    }
};