class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
            return 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int prod=1,digit=9;
            for(int j=1;j<=i;j++){
                if(j==1){
                    prod*=digit;
                    continue;
                }
                prod*=digit;
                digit--;
            }
            ans+=prod;
        }
        return ans+1;
    }
};