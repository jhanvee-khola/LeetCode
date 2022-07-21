Recursive Solution
```
class Solution {
public:
int solve(string s,int i,int n){
if(i>=n){
return 1;
}
int ans=0;
if(s[i]!='0'){
ans=solve(s,i+1,n);
}
if((i+1<n) && ((s[i]=='1' && s[i+1]<='9') || (s[i]=='2' && s[i+1]<='6'))){
ans+=solve(s,i+2,n);
}
return ans;
}
int numDecodings(string s) {
int n=s.length();
return solve(s,0,n);
}
};
```