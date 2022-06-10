class Solution {
public:
    int lengthOfLongestSubstring(string s){
        unordered_map<char,int> u;
        int n=s.length(),start=0,end=0,ans=0;	
        while(end<n){    
            u[s[end]]++;      
            while(u[s[end]]!=1){
                u[s[start]]--;
                start++;
            }
            ans=max(ans,end-start+1);
            end++;        
        }
        return ans;
    }
};