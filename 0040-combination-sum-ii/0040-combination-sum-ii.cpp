class Solution {
public:
    void help(vector<vector<int>> &ans,vector<int> cand,vector<int> temp,int sum,int target,int ind){
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<cand.size();i++){
            if(i!=ind && cand[i]==cand[i-1]){
                continue;
            }
            temp.push_back(cand[i]);
            sum+=cand[i];
            help(ans,cand,temp,sum,target,i+1);
            temp.pop_back();
            sum-=cand[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(cand.begin(),cand.end());
        help(ans,cand,temp,0,target,0);
        return ans;
    }
};