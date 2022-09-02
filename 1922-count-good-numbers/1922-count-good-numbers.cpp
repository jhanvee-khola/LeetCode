class Solution {
public:
    long long mod=1000000007;
    long long power(long long a,long long n) {
        a%=mod;
        long long res=1;
        while(n>0){
            if(n&1){
                res=res*a%mod;
            }   
            a=a*a%mod;
            n>>=1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long odd=0,even=0;
        if(n%2==0){
            odd=n/2;
            even=n/2;
        }
        else{
            odd=n/2;
            even=odd+1;
        }
        long long a=power(5,even);
        long long b=power(4,odd);
        int ans=(a*b)%mod;
        return ans;
    }
};