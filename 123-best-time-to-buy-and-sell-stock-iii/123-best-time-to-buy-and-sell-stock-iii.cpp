class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        int b=-prices[i]+after[0][cap];
                        int nb=after[1][cap];
                        curr[buy][cap]=max(b,nb);
                    }
                    else{
                        int s=prices[i]+after[1][cap-1];
                        int ns=after[0][cap];
                        curr[buy][cap]=max(s,ns);
                    }
                }
            }
            after=curr;
        }
        return after[1][2];
    }
};