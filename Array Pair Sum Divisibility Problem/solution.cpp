//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size()&1){
            return false;
        }
        unordered_map<int,int> remFreq;
        for(int i=0;i<nums.size();i++){
            remFreq[nums[i]%k]++;
        }
        for(auto i:remFreq){
            int r=i.first;
            if(r==0 && remFreq[r]&1){
                return false;
            }
            if(r!=0 && remFreq[r]!=remFreq[k-r]){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
