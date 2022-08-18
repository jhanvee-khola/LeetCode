class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> freq;
        for(auto i:words){
            freq[i]++;
        }
        vector<int> ans;
        int n=words.size(),l=words[0].length(),len=n*l,m=s.length();
        for(int i=0;i<=m-len;i++){
            unordered_map<string,int> found;
            int j=0;
            for(;j<n;j++){
                string w=s.substr(i+j*l,l);
                if(freq.find(w)!=freq.end()){
                    found[w]++;
                    if(found[w]>freq[w]){
                        break;
                    }
                }
                else{
                    break;
                }
            }
            if(j==n){
                ans.push_back(i);
            }
        }
        return ans;
    }
};