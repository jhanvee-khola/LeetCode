//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s){
	    unordered_map<char,int> freq;
	    for(int i=0;i<s.length();i++){
	        freq[s[i]]++;
	    }
	    unordered_map<int,int> freq2;
	    for(auto it:freq){
	        freq2[it.second]++;
	    }
	    if(freq2.size()>2){
	        return false;
	    }
	    else if(freq2.size()<2){
	        return true;
	    }
	    else{
	        auto f1=freq2.begin();
	        auto f2=f1++;
	        int ff1=f1->second,ff2=f2->second;
	        if(ff1==1 && (f1->first-f2->first==1 || f1->first==1)){
	            return 1;
	        }
	        if(ff2==1 && (f2->first-f1->first==1 || f2->first==1)){
	            return 1;
	        }
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}

// } Driver Code Ends
