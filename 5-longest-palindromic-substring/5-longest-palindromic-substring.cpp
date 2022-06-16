class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        if(n==1){
           return s; 
        }
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i==n-1){
                break;
            } 
            dp[i][i+1]=(s[i]==s[i+1]);
        }
        //for example-> aba (length = 3) string will be palindromic if s[0] == s[2] && nonboundary characters substring is also palindrome(that can be checked by dp[])
        for(int i=n-3;i>=0;i--){
            for(int j=i+2;j<n;j++){
                dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1]);
            }
        }
        int mx=INT_MIN;  
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]==1 && j-i+1>mx){
                    mx=j-i+1;
                    ans=s.substr(i,j-i+1);
                }        
            }
        }
        return ans;
    }
};