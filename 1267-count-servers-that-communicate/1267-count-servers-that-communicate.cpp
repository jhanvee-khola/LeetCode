class Solution {
public:
    int countServers(vector<vector<int>>& serv) {
        vector<pair<int,int>> grid;
        for(int i=0;i<serv.size();i++){
            for(int j=0;j<serv[0].size();j++){
                if(serv[i][j]==1){
                    grid.push_back({i,j});
                }
            }
        }
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        for(int i=0;i<grid.size();i++){
            row[grid[i].first]++;
            col[grid[i].second]++;
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            if(row[grid[i].first]>1 || col[grid[i].second]>1){
                ans++;
            }
        }
        return ans;
    }
};