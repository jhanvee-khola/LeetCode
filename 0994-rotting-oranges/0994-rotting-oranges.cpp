class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int ans=-1;//starts from -1 to make up for the 1st iteration that happens at 0th minute
        vector<int> dir={-1,0,1,0,-1};
        while(!q.empty()){
            int s=q.size();
            while(s--){
                pair<int,int> node=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int xd=node.first+dir[i];
                    int yd=node.second+dir[i+1];
                    if(xd>=0 && yd>=0 && xd<m && yd<n && grid[xd][yd]==1){
                        grid[xd][yd]=2;
                        q.push({xd,yd});
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if(fresh>0){
            return -1;
        }
        if(ans==-1){
            return 0;//all oranges went rotten in 0th minute itself
        }
        return ans;
    }
};