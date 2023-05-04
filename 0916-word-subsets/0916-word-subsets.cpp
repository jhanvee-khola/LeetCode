class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        vector<string> ans;
        unordered_map<char,int> b;
        for(auto c:w2[0]){
            b[c]++;
        }
        for(int i=1;i<w2.size();i++){
            string s=w2[i];
            unordered_map<char,int> temp;
            for(auto c:s){
                temp[c]++;
            }
            for(auto it:temp){
                b[it.first]=max(it.second,b[it.first]);
            }
        }
        for(int i=0;i<w1.size();i++){
            string s=w1[i];
            unordered_map<char,int> a;
            for(auto c:s){
                a[c]++;
            }
            bool flag=true;
            for(auto it:b){
                if(a[it.first]<it.second){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(s);
            }
        }
        return ans;
    }
};