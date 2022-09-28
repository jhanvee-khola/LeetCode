class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        int n=answers.size();
        for(int i=0;i<n;i++){
            m[answers[i]]++;
        }
        int ans=0;
        for(auto i:m){
            int p=i.first+1;
            int q=i.second;
            ans+=(q/p)*p;
            if(q%p!=0){
                ans+=p;
            }
        }
        return ans;
    }
};