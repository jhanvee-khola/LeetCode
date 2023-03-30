//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void help(vector<string> &ans,string temp,string s,unordered_map<string,int> m,int ind){
        if(ind==s.length()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        string curr="";
        for(int i=ind;i<s.length();i++){
            curr+=s[i];
            if(m.find(curr)!=m.end()){
                help(ans,temp+curr+" ",s,m,i+1);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s){
        // code here
        vector<string> ans;
        unordered_map<string,int> m;
        for(auto i:dict){
            m[i]++;
        }
        string temp="";
        help(ans,temp,s,m,0);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
