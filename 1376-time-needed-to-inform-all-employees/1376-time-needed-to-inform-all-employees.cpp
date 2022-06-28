class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> time(n,0);
        time[headID]=0;
        for(int i=0;i<manager.size();i++){
            int sup=manager[i];
            while(sup!=-1){
                time[i]+=informTime[sup];
                sup=manager[sup];
            }
        }
        int total=0;
        for(int i=0;i<manager.size();i++){
            total=max(total,time[i]);
        }
        return total;
    }
};