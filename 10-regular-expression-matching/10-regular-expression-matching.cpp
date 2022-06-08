class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length(),m=p.length();
        bool dp[n+1][m+1];
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            dp[i][0]=false;
        }
        for(int j=1;j<=m;j++){
            bool b=true;
            for(int k=j-1;k>=0;k--){
                if((p[k]!='*' && p[k+1]=='*') || p[k]=='*'){
                    continue;
                }
                else{
                    b=false;
                    break;
                }
            }
            dp[0][j]=b;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    if(s[i-1]!=p[j-2] && p[j-2]!='.'){
                        dp[i][j]=dp[i][j-2];
                    }
                    else{
                        dp[i][j]=dp[i][j-2]||dp[i-1][j];
                    }
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[n][m];
    }
};