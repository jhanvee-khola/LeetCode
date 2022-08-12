class Solution {
public:
    vector<int> dir={0,1,0,-1,0};
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    q.push({i,j});
                }
                else{
                    grid[i][j]=-1;
                }
            }
        }
        int ans=-1;
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int r=i+dir[k];
                int c=j+dir[k+1];
                if(r<0 || c<0 || r==m || c==n || grid[r][c]!=-1){
                    continue;
                }
                grid[r][c]=1+grid[i][j];
                ans=max(ans,grid[r][c]);
                q.push({r,c});
            }
        }
        return ans;
    }
};