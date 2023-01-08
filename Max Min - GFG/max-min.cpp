//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
   public:
    int findSum(int a[], int n){
        int mini,maxi,i;
        if(n%2==0){
            mini=min(a[0],a[1]);
            maxi=max(a[0],a[1]);
            i=2;
        }
        else{
            mini=maxi=a[0];
            i=1;
        }
        while(i<n-1){
            if(a[i]<a[i+1]){
                if(a[i]<mini){
                    mini=a[i];
                }
                if(a[i+1]>maxi){
                    maxi=a[i+1];
                }
            }
            else{
                if(a[i+1]<mini){
                    mini=a[i+1];
                }
                if(a[i]>maxi){
                    maxi=a[i];
                }
            }
            i+=2;
        }
        int ans=mini+maxi;
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
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends