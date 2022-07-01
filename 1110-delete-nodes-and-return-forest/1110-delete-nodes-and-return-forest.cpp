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
    void returnForest(TreeNode* &root, vector<int>& to_delete,vector<TreeNode*>& forest){
        if(!root){
            return;
        }
        returnForest(root->left,to_delete,forest);
        returnForest(root->right,to_delete,forest);
        int r=root->val;
        if(find(to_delete.begin(),to_delete.end(),r)!=to_delete.end()){
            if(root->left){
                forest.push_back(root->left);
            }
            if(root->right){
                forest.push_back(root->right);
            }
            root=NULL;
            delete root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        returnForest(root,to_delete,forest);
        if(root){
            forest.push_back(root);
        }
        return forest;
    }
};