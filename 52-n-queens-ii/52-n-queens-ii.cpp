class Solution {
public:
    bool isSafe(vector<vector<int>> pos,int x,int y,int n){
        //column check
        for(int i=0;i<x;i++){
            if(pos[i][y]){
                return false;
            }
        }
        //north-west diagonal
        int i=x-1,j=y-1;
        while(i>=0 && j>=0){
            if(pos[i][j]){
                return false;
            }
            i--;
            j--;
        }
        //north-east diagonal
        i=x-1,j=y+1;
        while(i>=0 && j<n){
            if(pos[i][j]){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }

    void nQueen(vector<vector<int>> pos,int row,int n,int *a){
        if(row==n){
            *a=*a+1;
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(pos,row,col,n)){
                pos[row][col]=1;
                nQueen(pos,row+1,n,a);
                pos[row][col]=0;
            }
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<vector<int>> pos(n,vector<int>(n,0));
        nQueen(pos,0,n,&ans);
        return ans;
    }
};