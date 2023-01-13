class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while(n){
            int r=n%10;
            digits.push_back(r);
            n/=10;
        }
        reverse(digits.begin(),digits.end());
        int num=digits.size();
        int i,j;
        for(i=num-2;i>=0;i--){
            if(digits[i]<digits[i+1]){
                break;
            }
        }
        if(i<0){
            return -1;
        }
        for(j=num-1;j>i;j--){
             if(digits[j]>digits[i]){
                 break;
             }
        }
        swap(digits[i],digits[j]);
        reverse(digits.begin()+i+1,digits.end());
        long ans=0;
        for(int k=0;k<num;k++){
            ans=ans*10+digits[k];
        }
        if(log2(ans)>=31){
            return -1;
        }
        return ans;
    }
};