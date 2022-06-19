class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(),products.end());
        int start=0,end=products.size()-1;
        for(int i=0;i<searchWord.length();i++) {
            vector<string> res;
            char c=searchWord[i];
            while(start<=end && (products[start].length()==i || products[start][i]<c)){
                start++;
            } 
            while(start<=end && (products[end].length()==i || products[end][i]>c)){
                end--;
            } 
            for(int j=0;j<3 && start+j<=end;j++){
                res.push_back(products[start+j]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};