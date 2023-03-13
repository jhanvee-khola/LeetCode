nclude<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string s) {
        long long zero=0,one=0,two=0,n=s.length();
        long long ans=0;
        map<pair<int,int>,int> diffFreq;
        diffFreq[{0,0}]=1;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero++;
            }
            else if(s[i]=='1'){
                one++;
            }
            else{
                two++;
            }
            pair<int,int> d={one-zero,two-one};
            if(diffFreq.find(d)==diffFreq.end()){
                diffFreq[d]=1;
            }
            else{
                ans+=diffFreq[d];
                diffFreq[d]++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}

// } Driver Code Ends
