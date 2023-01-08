//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
   public:
//1st Method
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
//2nd Method
    pair<int,int> minMax(int a[],int start,int end){
    	if(start==end){
	    return {a[start],a[end]};
	}
	if(start+1==end){
	    int mini=min(a[start],a[end]);
	    int maxi=max(a[start],a[end]);
	    return {mini,maxi};
	}
	int mid=(start+end)/2;
	pair<int,int> mml=minMax(a,start,mid);
	pair<int,int> mmr=minMax(a,mid+1,end);
	pair<int,int> ans;
	if(mml.first<mmr.first){
	    ans.first=mml.first;
	}
	else{
	    ans.first=mmr.first;
	}
	if(mml.second>mmr.second){
	    ans.second=mml.second;
	}
	else{
	    ans.second=mmr.second;
	}
	return ans;
    }
    int findSum2(int a[],int n){
    	pair<int,int> mm=minMax(a,0,n-1);
	return mm.first+mm.second;
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
