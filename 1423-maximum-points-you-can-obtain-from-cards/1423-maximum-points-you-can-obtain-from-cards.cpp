class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int totalSum=0,n=cp.size(),wsum=0;
        for(int i=0;i<n;i++){
            totalSum+=cp[i];
            if(i<n-k){
                wsum+=cp[i];
            }
        }
        int ans=0,j=n-k,i=0;
        ans=max(ans,totalSum-wsum);
        while(j<n){
            wsum-=cp[i++];
            wsum+=cp[j++];
            ans=max(ans,totalSum-wsum);
        }
        return ans;
    }
};