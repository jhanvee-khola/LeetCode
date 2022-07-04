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
    int ans=0;
    int leftLeaf(TreeNode* root,bool b){
        if(!root){
            return 0;
        }
        if(!root->left && !root->right && b){
            return root->val;
        }
        if(!root->left && !root->right){
            return 0;
        }
        return ans+leftLeaf(root->left,true)+leftLeaf(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return leftLeaf(root,false);
    }
};