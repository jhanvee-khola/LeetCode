class Solution {
public:
    int dp[101];
    int solve(string s,int i,int n){
        if(i>=n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        if(s[i]!='0'){
            ans=solve(s,i+1,n);
        }
        if((i+1<n) && ((s[i]=='1' && s[i+1]<='9') || (s[i]=='2' && s[i+1]<='6'))){
            ans+=solve(s,i+2,n);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        return solve(s,0,n);
    }
};