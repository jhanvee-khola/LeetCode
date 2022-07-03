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
    TreeNode* arrayToBST(vector<int>& nums,int l,int r){
        int mid=l+(r-l)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        if(mid-1>=l){
            root->left=arrayToBST(nums,l,mid-1);
        }
        if(mid+1<=r){
            root->right=arrayToBST(nums,mid+1,r);
        }
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        return arrayToBST(nums,l,r);
    }
};