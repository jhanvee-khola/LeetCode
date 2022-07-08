class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            int d=pow(points[i][0],2)+pow(points[i][1],2);
            pq.push({d,i});
        }
        vector<vector<int>> ans;
        while(k-- && !pq.empty()){
            int i=pq.top().second;
            ans.push_back(points[i]);
            pq.pop();
        }
        return ans;
    }
};