class Solution {
public:
    int minPartitions(string n) {
        int l=n.length();
        int maxDigit=0;
        for(int i=0;i<l;i++){
            int digit=n[i]-'0';
            maxDigit=max(maxDigit,digit);
        }
        return maxDigit;
    }
};