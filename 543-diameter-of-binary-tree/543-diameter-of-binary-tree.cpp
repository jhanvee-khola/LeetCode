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
    pair<int,int> diameter(TreeNode *root){
        pair<int,int> p;
        if(!root){
            p.first=p.second=0;
            return p;
        }
        pair<int,int> l=diameter(root->left);
        pair<int,int> r=diameter(root->right);
        
        p.first=max(l.first,r.first)+1;
        p.second=max(l.first+r.first,max(l.second,r.second));
        return p;
    }
    int diameterOfBinaryTree(TreeNode* root) {      
        if(!root){
            return 0;
        }
        pair<int,int> p=diameter(root);
        return p.second;
    }
};