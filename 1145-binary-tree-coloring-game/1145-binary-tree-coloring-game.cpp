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
    int dfs(TreeNode *root,vector<int>& depth,int &leftC,int &rightC,int x){
        if(!root){
            return 0;
        }
        int l=dfs(root->left,depth,leftC,rightC,x);
        int r=dfs(root->right,depth,leftC,rightC,x);
        depth[root->val]=l+r+1;
        if(root->val==x){
            if(root->left){
                leftC=root->left->val;
            }
            if(root->right){
                rightC=root->right->val;
            }
        }
        return depth[root->val];
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector<int> depth(n+1,0);
        int leftC=-1;
        int rightC=-1;
        dfs(root,depth,leftC,rightC,x);
        int xdep=depth[x];
        if(n-xdep>xdep){
            return true;
        }
        if(leftC!=-1 && n-depth[leftC]<depth[leftC]){
            return true;
        }
        if(rightC!=-1 && n-depth[rightC]<depth[rightC]){
            return true;
        }
        return false;
    }
};