class Solution {
public:
    bool possible(vector<int> weights,int capacity,int d){
        int days=1,total=0,i=0;
        while(i<weights.size()){
            total+=weights[i];
            if(total>capacity){
                days++;
                total=weights[i];
                if(days>d){
                    return false;
                }
            }
            i++;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int total=0,maxi=0;
        for(int i=0;i<weights.size();i++){
            total+=weights[i];
            maxi=max(maxi,weights[i]);
        }
        int start=maxi,end=total;
        while(start<end){
            int mid=(start+end)/2;
            if(possible(weights,mid,days)){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }
};