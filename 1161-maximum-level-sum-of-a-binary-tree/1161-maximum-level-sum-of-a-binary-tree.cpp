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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=INT_MIN,minLevel=0;
        int i=1;
        while(!q.empty()){
            int s=q.size();
            int temp=0;
            for(int i=0;i<s;i++){
                TreeNode *f=q.front();
                q.pop();
                temp+=f->val;
                if(f->left){
                    q.push(f->left);
                }
                if(f->right){
                    q.push(f->right);
                }
            }
            if(temp>ans){
                ans=temp;
                minLevel=i;
            }
            else if(temp==ans){
                minLevel=min(minLevel,i);
            }
            i++;
        }
        return minLevel;
    }
};