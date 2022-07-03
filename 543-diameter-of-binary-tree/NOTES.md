O(n^2) solution
```
class Solution {
public:
int height(TreeNode *root){
if(!root){
return 0;
}
return max(height(root->left),height(root->right))+1;
}
int diameterOfBinaryTree(TreeNode* root) {
if(!root){
return 0;
}
int l=height(root->left);
int r=height(root->right);
int op1=l+r;
int op2=diameterOfBinaryTree(root->left);
int op3=diameterOfBinaryTree(root->right);
return max(op1,max(op2,op3));
}
};
```