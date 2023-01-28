class Solution {
public:
    double myPow(double x, int n) {
        if(n<0){
            x=1/x;
        }
        long y=abs(n);
        double ans=1;
        while(y){
            if(y&1){
                ans=ans*x;
            }
            x=x*x;
            y>>=1;
        }
        return ans;
    }
};