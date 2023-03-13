class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
        vector<pair<int,int>> projects;
        int n=profit.size();
        for(int i=0;i<n;i++){
            projects.push_back({capital[i],profit[i]});
        }
        sort(projects.begin(),projects.end());
        priority_queue<int> maxprofit;
        int i=0;
        while(k--){
            while(i<n && projects[i].first<=w){
                maxprofit.push(projects[i].second);
                i++;
            }
            if(maxprofit.empty()){
                break;
            }
            w+=maxprofit.top();
            maxprofit.pop();
        }
        return w;
    }
};