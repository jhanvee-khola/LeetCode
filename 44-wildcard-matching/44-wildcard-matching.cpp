class Solution {
public:
    bool isMatch(string s, string t) {
        int n=s.length(),m=t.length();
        bool dp[n+1][m+1];
        memset(dp,true,sizeof(dp));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            dp[i][0]=false;
        }
        for(int i=1;i<=m;i++){
            for(int j=0;j<i;j++){
                if(t[j]!='*'){
                    dp[0][i]=false;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1] || t[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(t[j-1]=='*'){
                    dp[i][j]=dp[i][j-1]||dp[i-1][j];
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[n][m];
    }
};