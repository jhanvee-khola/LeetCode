class Solution {
public:
    bool possible(vector<int> piles,int speed,int h){
        int hours=0,i=0;
        while(i<piles.size()){
            hours+=(piles[i]-1)/speed+1;
            if(hours>h){
                return false;
            }
            i++;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int start=1,end=maxi;
        while(start<end){
            int mid=(start+end)/2;
            if(possible(piles,mid,h)){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};