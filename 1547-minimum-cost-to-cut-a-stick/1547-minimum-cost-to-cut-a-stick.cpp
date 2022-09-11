class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(m+2,vector<int>(m+2,0));
        for(int i=m;i>=1;i--){
            for(int j=i;j<=m;j++){
                int mini=1e9;
                for(int k=i;k<=j;k++){
                    int price=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini,price);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][m];
    }
};