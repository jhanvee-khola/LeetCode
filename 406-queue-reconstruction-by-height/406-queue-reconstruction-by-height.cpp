class Solution {
public:
    static bool compare(vector<int> a,vector<int> b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        vector<vector<int>> update;
        sort(people.begin(),people.end(),compare);
        for(int i=0;i<n;i++){
            int ind=people[i][1];
            update.insert(update.begin()+ind,people[i]);
        }
        return update;
    }
};