class Solution {
public:
    int help(string ring,string key,int i,int j,unordered_map<char,vector<int>> &m,vector<vector<int>> &dp){
        if(j==key.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int len=ring.length(),ans=INT_MAX;
        for(auto it:m[key[j]]){
            int d=abs(i-it);
            ans=min(ans,min(d,len-d)+help(ring,key,it,j+1,m,dp));
        }
        return dp[i][j]=ans+1;
    }
    int findRotateSteps(string ring, string key) {
        unordered_map<char,vector<int>> m;
        for(int i=0;i<ring.size();i++){
            char c=ring[i];
            m[c].push_back(i);
        }
        vector<vector<int>> dp(ring.size(),vector<int>(key.size(),-1));
        return help(ring,key,0,0,m,dp);
    }
};