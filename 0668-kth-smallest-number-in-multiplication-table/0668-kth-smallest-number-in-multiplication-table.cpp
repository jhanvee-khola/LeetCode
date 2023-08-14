class Solution {
public:
    int cntLess(int x,int m,int n){
        int cnt=0;
        for(int i=1;i<=m;i++){
            cnt+=min(x/i,n);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) {
        int l=1,r=m*n,ans;
        while(l<=r){
            int mid=(l+r)/2;
            int d=cntLess(mid,m,n);
            if(d<k){
                l=mid+1;
            }
            else{
                r=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};