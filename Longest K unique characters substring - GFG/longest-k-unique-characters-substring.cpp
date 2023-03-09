//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        unordered_map<char,int> freq;
        int start=0,ans=-1;
        for(int end=0;end<s.length();end++){
            freq[s[end]]++;
            while(freq.size()>k){
                freq[s[start]]--;
                if(freq[s[start]]==0){
                    freq.erase(s[start]);
                }
                start++;
            }
            if(freq.size()==k){
                ans=max(ans,end-start+1);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends