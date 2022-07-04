class Solution {
public:
    int numSplits(string s) {
        int n=s.length();
        int pref[n];
        pref[0]=1;
        map<char,int> preMap;
        preMap.insert({s[0],1});
        
        int suff[n];
        suff[n-1]=1;
        map<char,int> sufMap;
        sufMap.insert({s[n-1],1});
        
        for(int i=1;i<n;i++){
            char ch=s[i];
            if(preMap.find(ch)==preMap.end()){
                pref[i]=pref[i-1]+1;
                preMap.insert({ch,1});
            }
            else{
                pref[i]=pref[i-1];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            char ch=s[i];
            if(sufMap.find(ch)==sufMap.end()){
                suff[i]=suff[i+1]+1;
                sufMap.insert({ch,1});
            }
            else{
                suff[i]=suff[i+1];
            }
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            if(pref[i]==suff[i+1]){
                count++;
            }
        }
        return count;
    }
};