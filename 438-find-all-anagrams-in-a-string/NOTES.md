Method 2
```
class Solution {
public:
vector<int> findAnagrams(string s, string p) {
vector<int> ans;
if(s.length()<p.length()){
return ans;
}
int start=0,end=p.length()-1;
unordered_map<char,int> mp,ms;
for(int i=0;i<p.length();i++){
mp[p[i]]++;
ms[s[i]]++;
}
int m=p.length();
for(int i=m;i<s.length();i++){
if(ms==mp){
ans.push_back(i-m);
}
ms[s[i]]++;
ms[s[i-m]]--;
if(ms[s[i-m]]==0){
ms.erase(s[i-m]);
}
}
if (ms == mp){
ans.push_back(s.length()-m);
}
return ans;
}
};
```