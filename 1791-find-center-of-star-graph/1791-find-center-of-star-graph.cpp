class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a=edges[0][0],b=edges[0][1],c=edges[1][0],d=edges[1][1];
        int ans;
        if(a==c || a==d){
            ans=a;
        }
        if(b==c || b==d){
            ans=b;
        }
        return ans;
    }
};