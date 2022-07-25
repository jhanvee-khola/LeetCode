class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> mp;
        for(int i=0;i<names.size();i++){
            if(mp.find(names[i])!=mp.end()){
                int k=mp[names[i]];
                string s=names[i];
                string t=s+"("+to_string(k)+")";
                while(mp.find(t)!=mp.end()){
                    k++;
                    mp[names[i]]++;
                    t=s+"("+to_string(k)+")";
                }
                mp[names[i]]++;
                names[i]=t;
            }
            mp[names[i]]=1;
        }
        return names;
    }
};