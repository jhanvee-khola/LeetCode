class Solution {
public:
    bool checkUnique(string s){
        set<char> distinctChar;
        for(auto ch:s){
            distinctChar.insert(ch);
        }
        return s.length()==distinctChar.size();
    }
    void maxUnique(vector<string>& arr,string temp,int i,int &ans){
        if(!checkUnique(temp)){
            return;
        }
        else{
            int x=temp.size();
            ans=max(ans,x);
        }
        for(int j=i;j<arr.size();j++){
            maxUnique(arr,temp+arr[j],j+1,ans);
        }
        return;
    } 
    int maxLength(vector<string>& arr) {
        string temp="";
        int ans=INT_MIN;
        maxUnique(arr,temp,0,ans);
        return ans;
    }
};