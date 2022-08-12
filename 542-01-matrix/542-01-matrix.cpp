class Solution {
public:
    vector<int> dir={0,1,0,-1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else{
                    mat[i][j]=-1;
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int r=i+dir[k];
                int c=j+dir[k+1];
                if(r<0 || c<0 || r==m || c==n || mat[r][c]!=-1){
                    continue;
                }
                mat[r][c]=1+mat[i][j];
                q.push({r,c});
            }
            
        }
        return mat;
    }
};