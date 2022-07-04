class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int prefix[n];
        int suffix[n];
        prefix[0]=suffix[n-1]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                prefix[i]=1+prefix[i-1];
            }
            else{
                prefix[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                suffix[i]=1+suffix[i+1];
            }
            else{
                suffix[i]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(prefix[i],suffix[i]);
        }
        return ans;
    }
};