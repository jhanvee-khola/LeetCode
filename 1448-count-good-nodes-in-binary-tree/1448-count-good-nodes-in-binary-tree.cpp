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
    int isGood(TreeNode* root,int maxi){
        if(!root){
            return 0;
        }
        maxi=max(maxi,root->val);
        if(root->val>=maxi){
            return 1+isGood(root->left,maxi)+isGood(root->right,maxi);
        }
        return isGood(root->left,maxi)+isGood(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        int r=root->val;
        return isGood(root,r);
    }
};