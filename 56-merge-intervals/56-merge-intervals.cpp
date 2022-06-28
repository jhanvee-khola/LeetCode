class Solution {
public:
    static bool compare(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> update;
        if(intervals.size()==0){
            return update;
        }
        sort(intervals.begin(),intervals.end(),compare);
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