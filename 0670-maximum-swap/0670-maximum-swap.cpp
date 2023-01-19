class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        int n=num;
        while(n){
            int r=n%10;
            digits.push_back(r);
            n/=10;
        }
        reverse(digits.begin(),digits.end());
        int maxDigit=-1,maxInd=-1,leftInd=-1,rightInd=-1;
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]>maxDigit){
                maxDigit=digits[i];
                maxInd=i;
            }
            if(digits[i]<maxDigit){
                leftInd=i;
                rightInd=maxInd;
            }
        }
        if(leftInd==-1){
            return num;
        }
        swap(digits[rightInd],digits[leftInd]);
        int ans=0;
        for(int i=0;i<digits.size();i++){
            ans=ans*10+digits[i];
        }
        return ans;
    }
};