/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct myComp {
        constexpr bool operator()(
            pair<TreeNode*,int> const& a,
            pair<TreeNode*,int> const& b)
            const noexcept{
                return a.first->val>b.first->val;
            }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<pair<TreeNode*,int>,vector<pair<TreeNode*,int>>,myComp> parent;
        priority_queue<pair<TreeNode*,int>,vector<pair<TreeNode*,int>>,myComp> child;
        map<int,vector<int>> vertical;
        int mini=0,maxi=0;
        parent.push({root,0});
        while(!parent.empty() || !child.empty()){
            if(parent.empty()){
                priority_queue<pair<TreeNode*,int>,vector<pair<TreeNode*,int>>,myComp> temp=parent;
                parent=child;
                child=temp;
            }
            TreeNode *n=parent.top().first;
            int hz=parent.top().second;
            mini=min(mini,hz);
            maxi=max(maxi,hz);
            parent.pop();
            if(vertical.find(hz)==vertical.end()){
                vector<int> temp;
                vertical.insert({hz,temp});
            }
            vertical[hz].push_back(n->val);
            if(n->left){
                child.push({n->left,hz-1});
            }
            if(n->right){
                child.push({n->right,hz+1});
            }
        }
        vector<vector<int>> ans;
        for(int i=mini;i<=maxi;i++){
            ans.push_back(vertical[i]);
        }
        return ans;
    }
};