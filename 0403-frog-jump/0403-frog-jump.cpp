class Solution {
public:
    vector<int> dy={-1,0,1};
    int bs(vector<int> &stones,int start,int end,int target){
        while(start<=end){
            int mid=(start+end)/2;
            if(stones[mid]==target){
                return mid;
            }
            else if(stones[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
    bool help(vector<int> &stones,int i,int prev,vector<vector<int>> &dp){
        if(i==stones.size()-1){
            return true;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        bool ans=false;
        for(int j=0;j<3;j++){
            int ind=bs(stones,i+1,stones.size()-1,stones[i]+prev+dy[j]);
            if(ind!=-1){
                ans=ans||help(stones,ind,prev+dy[j],dp);
            }
        }
        return dp[i][prev]=ans;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1){
            return false;
        }
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size(),-1));
        return help(stones,1,1,dp);
    }
};