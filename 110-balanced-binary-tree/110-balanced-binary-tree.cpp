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
    pair<int,bool> Balanced(TreeNode* root){
        pair<int,bool> p;
        if(root==NULL){
            p.first=0;
            p.second=true;
            return p;
        }
        pair<int,bool> l=Balanced(root->left);
        pair<int,bool> r=Balanced(root->right);
        p.first=max(l.first,r.first)+1;
        if(abs(l.first-r.first)<=1 && l.second && r.second){
            p.second=true;
        }
        else{
            p.second=false;
        }
        return p;
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans=Balanced(root);
        return ans.second;
    }
};