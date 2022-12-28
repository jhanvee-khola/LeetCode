class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<=i-2;j++){
                temp.push_back(ans[i-2][j-1]+ans[i-2][j]);
            }
            if(i!=1){
                temp.push_back(1);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};