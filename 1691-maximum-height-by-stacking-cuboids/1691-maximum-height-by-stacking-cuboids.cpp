class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& cube:cuboids){
            sort(cube.begin(),cube.end());
        }
        cuboids.push_back({0,0,0});
        sort(cuboids.begin(),cuboids.end());
        int n=cuboids.size(),ans=0;
        vector<int> dp(n);
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(cuboids[prev][0]<=cuboids[i][0] && cuboids[prev][1]<=cuboids[i][1] && cuboids[prev][2]<=cuboids[i][2]){
                    dp[i]=max(dp[i],dp[prev]+cuboids[i][2]);
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};