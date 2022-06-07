class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> ans(n+1,0);
        for(int i=0;i<edges.size();i++){
            ans[edges[i][0]]++;
            ans[edges[i][1]]++;
        }
        int t;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==n-1){
                t=i;
                break;
            }
        }
        return t;
    }
};