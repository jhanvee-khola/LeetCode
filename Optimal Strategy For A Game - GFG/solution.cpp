//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long help(int arr[],int start,int end,vector<vector<int>> &dp){
        if(start>end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        long long a=help(arr,start+1,end-1,dp);
        long long c1=arr[start]+min(a,help(arr,start+2,end,dp));
        long long c2=arr[end]+min(a,help(arr,start,end-2,dp));
        
        return dp[start][end]=max(c1,c2);
    }
    long long maximumAmount(int arr[], int n){
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return help(arr,0,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
