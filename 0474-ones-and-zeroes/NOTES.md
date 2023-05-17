Recursion
```
class Solution {
public:
    int help(vector<pair<int,int>> oz,int i,int m,int n){
        if(i==oz.size() || (m==0 && n==0)){
            return 0;
        }
        if(m-oz[i].first<0 || n-oz[i].second<0){
            return help(oz,i+1,m,n);
        }
        return max(1+help(oz,i+1,m-oz[i].first,n-oz[i].second),help(oz,i+1,m,n));
    }
    int findMaxForm(vector<string>& strs,int m,int n) {
        int l=strs.size();
        vector<pair<int,int>> oz(l,{0,0});
        for(int i=0;i<l;i++){
            for(auto c:strs[i]){
                if(c=='0'){
                    oz[i].first++;
                }
                else{
                    oz[i].second++;
                }
            }
        }
        return help(oz,0,m,n);
    }
```
Top down dp
```
	class Solution {
public:
    int dp[601][101][101];
    int help(vector<pair<int,int>> oz,int i,int m,int n){
        if(i==oz.size() || (m==0 && n==0)){
            return 0;
        }
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        if(m-oz[i].first<0 || n-oz[i].second<0){
            return dp[i][m][n]=help(oz,i+1,m,n);
        }
        return dp[i][m][n]=max(1+help(oz,i+1,m-oz[i].first,n-oz[i].second),help(oz,i+1,m,n));
    }
    int findMaxForm(vector<string>& strs,int m,int n) {
        int l=strs.size();
        vector<pair<int,int>> oz(l,{0,0});
        for(int i=0;i<l;i++){
            for(auto c:strs[i]){
                if(c=='0'){
                    oz[i].first++;
                }
                else{
                    oz[i].second++;
                }
            }
        }
        memset(dp,-1 ,sizeof(dp));
        return help(oz,0,m,n);
    }
};
```
