class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<int> prev(2,0),curr(2,0);
        prev[0]=prev[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    int b=-p[i]+prev[0];
                    int nb=prev[1];
                    curr[j]=max(b,nb);
                }
                else{
                    int s=p[i]+prev[1];
                    int ns=prev[0];
                    curr[j]=max(s,ns);
                }
            }
            prev=curr;
        }
        return prev[1];
    }
};