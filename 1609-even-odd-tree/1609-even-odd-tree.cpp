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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int j=0,prev=-1;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode *n=q.front();
                q.pop();
                if(j%2==0){
                    if(n->val%2==0){
                        return false;
                    }
                    if(prev!=-1 && n->val<=prev){
                        return false;
                    }
                }
                else{
                    if(n->val%2==1){
                        return false;
                    }
                    if(prev!=-1 && n->val>=prev){
                        return false;
                    }
                }
                prev=n->val;
                if(n->left){
                    q.push(n->left);
                }
                if(n->right){
                    q.push(n->right);
                }
            }
            j++;
            prev=-1;
        }
        return true;
    }
};