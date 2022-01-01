class Solution {
public:
    int maxPower(string s) {
        int ans=1,cpower=1;
        for(int i=1;i<s.length();){
            if(s[i]!=s[i-1]){
                cpower=1;
                i++;
                continue;
            }
            while(i<s.length() && s[i]==s[i-1]){
                cpower++;
                i++;
            }
            ans=max(ans,cpower);
            if(s[i]!=s[i-1]){
                cpower=1;
            }
        }
        return ans;
    }
};