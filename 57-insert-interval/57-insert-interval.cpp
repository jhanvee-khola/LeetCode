class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> update;
        int i=0;
        while(i<intervals.size() && intervals[i][0]<newInterval[0]){
            i++;
        }
        intervals.insert(intervals.begin()+i,newInterval);
        vector<int> temp=intervals[0];
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]<=temp[1]){
                temp[0]=min(temp[0],intervals[i][0]);
                temp[1]=max(temp[1],intervals[i][1]);
            }
            else{
                update.push_back(temp);
                temp=intervals[i];
            }
        }
        update.push_back(temp);
        return update;
    }
};