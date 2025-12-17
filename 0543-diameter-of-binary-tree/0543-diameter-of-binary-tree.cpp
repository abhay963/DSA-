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
int findheight(TreeNode* root){
  if(root==NULL)return 0;
  return 1+max(findheight(root->left),findheight(root->right));
}
void solve(TreeNode* root,int &maxi){
  if(root==NULL)return;
  int lh=findheight(root->left);
  int rh=findheight(root->right);
  maxi=max(maxi,lh+rh);
  solve(root->left,maxi);
  solve(root->right,maxi);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        solve(root,maxi);
        return maxi;
    }
};