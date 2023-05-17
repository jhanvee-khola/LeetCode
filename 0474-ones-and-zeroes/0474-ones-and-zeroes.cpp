class Solution {
public:
    int findMaxForm(vector<string>& strs,int m,int n){
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(auto s:strs){
            int nz=count(s.begin(),s.end(),'0');
            int no=s.length()-nz;
            for(int i=m;i>=nz;i--){
                for(int j=n;j>=no;j--){
                    dp[i][j]=max(dp[i][j],1+dp[i-nz][j-no]);
                }
            }
        }
        return dp[m][n];
    }
};