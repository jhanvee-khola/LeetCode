class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[]={0,0,1,-1,1,-1,1,-1};
        int dy[]={1,-1,0,0,1,1,-1,-1};
        int m=board.size(),n=board[0].size();
        vector<vector<bool>> change(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;
                for(int k=0;k<8;k++){
                    if(i+dx[k]>=m || i+dx[k]<0 || j+dy[k]>=n || j+dy[k]<0){
                        continue;
                    }
                    if(board[i+dx[k]][j+dy[k]]){
                        count++;
                    }
                }
                if(count<2 || count>3){
                    change[i][j]=false;
                }
                else if(board[i][j] && (count==2 || count==3)){
                    change[i][j]=true;
                }
                else if(!board[i][j] && count==3){
                    change[i][j]=true;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=change[i][j];
            }
        }
    }
};