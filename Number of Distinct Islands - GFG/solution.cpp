//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(vector<vector<int>> &grid,vector<vector<int>> &visit,vector<pair<int,int>> &v,
  int i,int j,int i0,int j0){
      visit[i][j]=1;
      v.push_back({i-i0,j-j0});
      vector<int> dir={0,1,0,-1,0};
      for(int k=0;k<4;k++){
          int x=i+dir[k];
          int y=j+dir[k+1];
          if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y] && !visit[x][y]){
              dfs(grid,visit,v,x,y,i0,j0);
          }
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visit(n,vector<int>(m,0));
        set<vector<pair<int,int>>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visit[i][j] && grid[i][j]==1){
                    vector<pair<int,int>> v;
                    dfs(grid,visit,v,i,j,i,j);
                    s.insert(v);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends
