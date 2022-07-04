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
    int prev=INT_MAX,minDiff=INT_MAX;
    void getMin(TreeNode* root){
        if(!root){
            return;
        }
        getMin(root->left);
        if(prev==INT_MAX){
            prev=root->val;
        }
        else{
            minDiff=min(minDiff,abs(root->val-prev));
            prev=root->val;
        }
        getMin(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        getMin(root);
        return minDiff;
    }
};