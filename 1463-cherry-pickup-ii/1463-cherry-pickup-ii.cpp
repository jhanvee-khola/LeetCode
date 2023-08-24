class Solution {
public:
    int dy[3]={0,-1,1};
    int dp[71][71][71];
    int help(vector<vector<int>>& grid,int i,int j1,int j2){
        int n=grid.size(),m=grid[0].size();
        if(i==n){
            return 0;
        }
        if(j1>=m || j2>=m || j1<0 || j2<0){
            return INT_MIN;
        }
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        int total=0;
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                total=max(total,help(grid,i+1,j1+dy[x],j2+dy[y]));
            }
        }
        if(j1==j2){
            total+=grid[i][j1];
        }
        else{
            total+=(grid[i][j1]+grid[i][j2]);
        }
        return dp[i][j1][j2]=total;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return help(grid,0,0,m-1);
    }
};