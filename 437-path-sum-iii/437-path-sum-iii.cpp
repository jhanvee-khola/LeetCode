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
    int paths(TreeNode* root,long curr,int target){
        if(!root){
            return 0;
        }
        long sum=curr+root->val;
        return (sum==target)+paths(root->left,sum,target)+paths(root->right,sum,target);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        return paths(root,0,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};