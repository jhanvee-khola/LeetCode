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
    void rootToLeafSum(TreeNode *root,int currSum){
        if(!root->left && !root->right){
            int d=currSum*10+root->val;
            ans+=d;
            return;
        }
        if(root->left){
            rootToLeafSum(root->left,currSum*10+root->val);
        }
        if(root->right){
            rootToLeafSum(root->right,currSum*10+root->val);
        }
    }
    int sumNumbers(TreeNode* root){
        if(!root){
            return 0;
        }
        rootToLeafSum(root,0);
        return ans;
    }
};