```
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
bool found(TreeNode* root,TreeNode* p){
if(!root){
return false;
}
if(root==p){
return true;
}
return found(root->left,p)||found(root->right,p);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
if(root==p || root==q){
return root;
}
if((found(root->left,p) && found(root->right,q)) || (found(root->right,p) && found(root->left,q))){
return root;
}
if(found(root->left,p) && found(root->left,q)){
return lowestCommonAncestor(root->left,p,q);
}
return lowestCommonAncestor(root->right,p,q);
}
};
```