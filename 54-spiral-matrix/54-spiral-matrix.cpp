class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> ans;
        int rStart=0,rEnd=matrix.size()-1,cStart=0,cEnd=matrix[0].size()-1;
        while(rStart<=rEnd && cStart<=cEnd){
            for(int i=cStart;i<=cEnd;i++){
                ans.push_back(matrix[rStart][i]);
            }
            rStart++;
            for(int i=rStart;i<=rEnd;i++){
                ans.push_back(matrix[i][cEnd]);
            }
            cEnd--;
            if(rStart<=rEnd){
                for(int i=cEnd;i>=cStart;i--){
                    ans.push_back(matrix[rEnd][i]);
                }
                rEnd--;
            }
            if(cStart<=cEnd){
                for(int i=rEnd;i>=rStart;i--){
                    ans.push_back(matrix[i][cStart]);
                }
                cStart++;
            }
        }
        return ans;
    }
};