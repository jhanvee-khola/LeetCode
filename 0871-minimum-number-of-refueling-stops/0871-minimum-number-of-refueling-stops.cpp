class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int pos=startFuel,ans=0,i=0;
        while(pos<target){
            while(i<stations.size() && stations[i][0]<=pos){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()){
                return -1;
            }
            pos+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};