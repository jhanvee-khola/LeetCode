class Solution {
public:
    void help(vector<vector<int>> &ans,vector<int> cand,vector<int> temp,int target,int sum,int ind){
        if(sum>target){
            return;
        }
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<cand.size();i++){
            temp.push_back(cand[i]);
            sum+=cand[i];
            help(ans,cand,temp,target,sum,i);
            temp.pop_back();
            sum-=cand[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        help(ans,cand,temp,target,0,0);
        return ans;
    }
};