class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<double,int> mp;
            int maxi=0;
            for(int j=i+1;j<n;j++){
                double dy=points[j][1]-points[i][1];
                double dx=points[j][0]-points[i][0];
                double slope=dy/dx;
                if(slope==(-1/(double)0)){
                    slope=1/(double)0;
                }
                mp[slope]++;
                if(mp[slope]>maxi){
                    maxi=mp[slope];
                }
            }
            ans=max(ans,maxi+1);
        }
        return ans;
    }
};