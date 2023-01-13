//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[],int n,int k){
        vector<pair<int,int>> a(k-1,{-1,0});
        for(int i=0;i<n;i++){
            int j;
            for(j=0;j<k-1;j++){
                if(a[j].first==arr[i]){
                    a[j].second++;
                    break;
                }
            }
            if(j==k-1){
                int l;
                for(l=0;l<k-1;l++){
                    if(a[l].second==0){
                        a[l].first=arr[i];
                        a[l].second=1;
                        break;
                    }
                }
                if(l==k-1){
                    for(l=0;l<k-1;l++){
                        a[l].second--;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<k-1;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(arr[j]==a[i].first){
                    count++;
                }
            }
            if(count>n/k){
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends