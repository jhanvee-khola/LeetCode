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
    TreeNode* prev=NULL;
    TreeNode* bstToGst(TreeNode* root) {   
        if(!root){
            return NULL;
        }
        root->right=bstToGst(root->right);
        if(prev){
            root->val=root->val+prev->val;
        }
        prev=root;
        root->left=bstToGst(root->left);
        return root;
    }
};