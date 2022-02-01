class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=0,s=0,ans=0;
        while(s<prices.size()){
            int d=prices[s]-prices[b];
            if(d<0){
                b=s;
            }
            else{
                ans=max(ans,d);
            }
            s++;
        }
        return ans;
    }
};