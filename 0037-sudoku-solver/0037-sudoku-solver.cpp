class Solution {
public:
    bool isSafe(vector<vector<char>> &board,int x,int y,char c){
        //row and column check
        for(int i=0;i<board.size();i++){
            if(board[x][i]==c || board[i][y]==c){
                return false;
            }
        }
        //sub-box check
        int n=(x/3)*3,m=(y/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[n+i][m+j]==c){
                    return false;
                }
            }
        }
        return true;
    }
    bool help(vector<vector<char>> &board,int i,int j){
        if(i>=board.size()){
            return true;
        }
        if(j>=board.size()){
            return help(board,i+1,0);
        }
        if(board[i][j]!='.'){
            return help(board,i,j+1);
        }
        for(char c='1';c<='9';c++){
            if(isSafe(board,i,j,c)){
                board[i][j]=c;
                if(help(board,i,j+1)){
                    return true;
                }
                else{
                    board[i][j]='.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        help(board,0,0);
    }
};