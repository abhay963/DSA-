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
bool solve(TreeNode* root,long long left1,long long right1){

  if(root==NULL)return true;
  if(root->val<=left1 || root->val>=right1)return false;
  
   if(solve(root->left,left1,root->val) &&   solve(root->right,root->val,right1) )return true; 
  
    return false;
  
  
}
    bool isValidBST(TreeNode* root) {
      if(root==NULL)return true;
        return solve(root,LLONG_MIN,LLONG_MAX);
    }
};