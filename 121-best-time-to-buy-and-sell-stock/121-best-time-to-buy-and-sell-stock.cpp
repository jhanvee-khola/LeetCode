class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=1,ans=0;
        while(r<prices.size()){
            int d=prices[r]-prices[l];
            if(d<0){
                l=r;
            }
            else{
                ans=max(ans,d);
            }
            r++;
        }
        return ans;
    }
};
