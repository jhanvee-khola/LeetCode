class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        int n=name.length(),m=typed.length();
        while(i<n && j<m){
            if(name[i]==typed[j]){
                i++;
                j++;
                continue;
            }
            if(j>0 && typed[j]==typed[j-1]){
                j++;
                continue;
            }
            return false;
        }
        if(i<n){
            return false;
        }
        while(j<m){
            if(typed[j]!=name[n-1]){
                return false;
            }
            j++;
        }
        return true;
    }
};