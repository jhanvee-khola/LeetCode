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
    void paths(TreeNode* root,string temp,vector<string>& ans){
        if(!root->left && !root->right){
            ans.push_back(temp+"->"+to_string(root->val));
            return;
        }
        if(root->left){
            paths(root->left,temp+"->"+to_string(root->val),ans);
        }
        if(root->right){
            paths(root->right,temp+"->"+to_string(root->val),ans);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp=to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(temp);
        }
        if(root->left){
            paths(root->left,temp,ans);
        }
        if(root->right){
            paths(root->right,temp,ans);
        }
        return ans;        
    }
};