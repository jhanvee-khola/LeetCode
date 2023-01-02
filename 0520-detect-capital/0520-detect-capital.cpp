class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==1){
            return true;
        }
        int i;
        if(word[0]<=90 && word[1]<=90){
            i=2;
            while(i<word.size()){
                if(word[i]>90){
                    return false;
                }
                i++;
            }
        }
        if(word[0]<=90 && word[1]>90){
            i=2;
            while(i<word.size()){
                if(word[i]<=90){
                    return false;
                }
                i++;
            }
        }
        if(word[0]>90){
            i=1;
            while(i<word.size()){
                if(word[i]<=90){
                    return false;
                }
                i++;
            }
        }
        return true;
    }
};