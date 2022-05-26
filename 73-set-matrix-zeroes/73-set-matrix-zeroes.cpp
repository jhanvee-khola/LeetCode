class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> col;
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(auto i:row){
            for(int j=0;j<n;j++){
                matrix[i][j]=0;
            }
        }
        for(auto i:col){
            for(int j=0;j<m;j++){
                matrix[j][i]=0;
            }
        }
    }
};