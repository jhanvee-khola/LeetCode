class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long M=1000000007;
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int maxWidth=verticalCuts[0],maxHeight=horizontalCuts[0];
        int hs=horizontalCuts.size(),vs=verticalCuts.size();
        for(int i=1;i<vs;i++){
            maxWidth=max(maxWidth,verticalCuts[i]-verticalCuts[i-1]);
        }
        maxWidth=max(maxWidth,w-verticalCuts[vs-1]);
        for(int i=1;i<hs;i++){
            maxHeight=max(maxHeight,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        maxHeight=max(maxHeight,h-horizontalCuts[hs-1]);
        return (maxHeight%M*maxWidth%M)%M;
    }
};