class Solution {
public:
    static bool comp(pair<int,int> a,pair<int,int> b){
        return a.first<b.first;
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> combine;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                combine.push_back({nums[i][j],i});
            }
        }
        sort(combine.begin(),combine.end(),comp);
        vector<int> ans;
        unordered_map<int,int> count;
        int k=0,start=0;
        for(int end=0;end<combine.size();end++){
            if(!count[combine[end].second]){  
                k++;
            }
            count[combine[end].second]++;
            if(k==nums.size()){
                while(count[combine[start].second]>1){
                    count[combine[start].second]--;
                    start++;
                }
                if(ans.empty() || ans[1]-ans[0]>combine[end].first-combine[start].first){
                    ans={combine[start].first,combine[end].first};
                }
            }
        }
        return ans;
    }
};