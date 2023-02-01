class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes="L"+dominoes+"R";
        string ans;
        for(int i=0,j=1;j<dominoes.length();j++){
            if(dominoes[j]=='.'){
                continue;
            }
            if(i>0){
                ans+=dominoes[i];
            }
            int tilesBtw=j-i-1;
            if(dominoes[i]==dominoes[j]){
                ans+=string(tilesBtw,dominoes[i]);
            }
            else if(dominoes[i]=='L' && dominoes[j]=='R'){
                ans+=string(tilesBtw,'.');
            }
            else{
                ans+=string(tilesBtw/2,'R');
                if(tilesBtw%2){
                    ans+=".";
                }
                ans+=string(tilesBtw/2,'L');
            }
            i=j;
        }
        return ans;
    }
};