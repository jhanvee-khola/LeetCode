class Solution {
public:
    static bool compare(vector<int> a,vector<int> b){
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        
        int i=0,n=boxTypes.size(),cnt=0,total=0;
        while(i<n && cnt<truckSize){
            if(cnt+boxTypes[i][0]<=truckSize){
                cnt+=boxTypes[i][0];
                total+=boxTypes[i][0]*boxTypes[i][1];
            }
            else{
                int k=truckSize-cnt;
                cnt+=k;
                total+=k*boxTypes[i][1];
            }
            i++;
        }
        return total;
    }
};