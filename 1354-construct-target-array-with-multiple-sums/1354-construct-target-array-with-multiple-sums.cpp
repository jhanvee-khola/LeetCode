class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        long tSum=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(target[i]);
            tSum+=target[i];
        }
        while(pq.top()!=1){
            long maxi=pq.top();
            pq.pop();
            tSum=tSum-maxi;
            if(tSum==0 || maxi-tSum<=0){
                return false;
            }
            if(tSum==1){
                return true;
            }
            int change=maxi%tSum;
            if(change==0){
                return false;
            }
            tSum+=change;
            pq.push(change);
        }
        return true;
    }
};