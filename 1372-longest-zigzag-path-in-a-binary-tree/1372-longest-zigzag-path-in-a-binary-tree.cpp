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
    void zigZag(TreeNode *root,bool left,int steps){
        if(!root){
            return;
        }
        ans=max(ans,steps);
        if(left){
            zigZag(root->left,false,steps+1);
            zigZag(root->right,true,1);
        }
        else{
            zigZag(root->right,true,steps+1);
            zigZag(root->left,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        zigZag(root,true,0);
        zigZag(root,false,0);
        return ans;
    }
};