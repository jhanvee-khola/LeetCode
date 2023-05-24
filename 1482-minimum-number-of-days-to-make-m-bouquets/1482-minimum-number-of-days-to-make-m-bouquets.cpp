class Solution {
public:
    bool canMake(vector<int> bd,int m,int k,int d){
        int cnt=0,flow=0;
        for(int i=0;i<bd.size();i++){
            if(bd[i]<=d){
                flow++;
            }
            else{
                flow=0;
            }
            if(flow==k){
                cnt++;
                flow=0;
            }
        }
        return cnt>=m;
    }
    int minDays(vector<int>& bd, int m, int k) {
        if(bd.size()/k<m){
            return -1;
        }
        int maxi=0;
        for(int i=0;i<bd.size();i++){
            maxi=max(maxi,bd[i]);
        }
        int l=0,r=maxi;
        while(l<r){
            int mid=l+(r-l)/2;
            if(canMake(bd,m,k,mid)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};