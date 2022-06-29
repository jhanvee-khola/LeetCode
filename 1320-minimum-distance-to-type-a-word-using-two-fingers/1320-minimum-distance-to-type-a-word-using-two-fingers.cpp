class Solution {
public:
    int mini(string word,int i,int f1,int f2,vector<vector<vector<int>>>& dp){
        if(i==word.length()){
            return 0;
        }
        if(dp[i][f1][f2]!=-1){
            return dp[i][f1][f2];
        }
        
        int x=(word[i]-'A')/6;
        int y=(word[i]-'A')%6;
        
        int f1x=f1==26?x:f1/6;
        int f1y=f1==26?y:f1%6;
        int f2x=f2==26?x:f2/6;
        int f2y=f2==26?y:f2%6;
        
        //26 position means the finger is free, hence we may as well assume that it is on (x,y) to give eventual dist as 0 to the target position
        
        int c1=abs(f1x-x)+abs(f1y-y);
        int c2=abs(f2x-x)+abs(f2y-y);

        int newPos=word[i]-'A';
        return dp[i][f1][f2]=min(c1+mini(word,i+1,newPos,f2,dp),c2+mini(word,i+1,f1,newPos,dp));
    }
    int minimumDistance(string word) {
        vector<vector<vector<int>>> dp(word.length(),vector<vector<int>>(27,vector<int>(27,-1)));
        return mini(word,0,26,26,dp);
    }
};