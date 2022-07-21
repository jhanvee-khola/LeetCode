class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int afterB,afterNB,currB,currNB;
        afterB=afterNB=0;
        for(int i=n-1;i>=0;i--){
            int b=-prices[i]+afterNB;
            int nb=afterB;
            currB=max(b,nb);
            
            int s=prices[i]-fee+afterB;
            int ns=afterNB;
            currNB=max(s,ns);
            
            afterB=currB;
            afterNB=currNB;
        }
        return afterB;
    }
};