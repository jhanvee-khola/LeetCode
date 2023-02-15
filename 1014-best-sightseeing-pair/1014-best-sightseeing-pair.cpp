class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=INT_MIN,rightMax=INT_MIN;
        for(int i=n-2;i>=0;i--){
            rightMax=max(rightMax,values[i+1]-(i+1));
            ans=max(ans,values[i]+i+rightMax);
        }
        return ans;
    }
};