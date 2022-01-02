class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans=0;
        vector<int>v(60,0);
        for(int i=0;i<time.size();i++){
            int a=time[i]%60;
            if(a==0){
                ans+=v[0];
            }  
            else{
                ans+=v[60-a];
            }
            v[a]++;
        }
        return ans;
    }
};