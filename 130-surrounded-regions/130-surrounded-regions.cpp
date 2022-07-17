class Solution {
public:
    void dfsTravel(vector<vector<char>> &board,int i,int j){
        board[i][j]='B';
        if(i+1<board.size() && board[i+1][j]=='O'){
            dfsTravel(board,i+1,j);
        }
        if(i-1>=0 && board[i-1][j]=='O'){
            dfsTravel(board,i-1,j);
        }
        if(j+1<board[0].size() && board[i][j+1]=='O'){
            dfsTravel(board,i,j+1);
        }
        if(j-1>=0 && board[i][j-1]=='O'){
            dfsTravel(board,i,j-1);
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if((i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1) && board[i][j]=='O'){
                    dfsTravel(board,i,j);
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='B'){
                    board[i][j]='O';
                }
            }
        }
    }
};