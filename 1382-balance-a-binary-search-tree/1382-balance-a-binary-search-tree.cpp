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
void solve(TreeNode* root,vector<int>& inorder){
  if(root==NULL)return ;
  solve(root->left,inorder);
  inorder.push_back(root->val);
  solve(root->right,inorder);
}

TreeNode* solve2(int low,int high,vector<int>& inorder){
  if(low>high)return NULL;
  int mid=low+(high-low)/2;
  TreeNode* root=new TreeNode(inorder[mid]);
  root->left=solve2(low,mid-1,inorder);
  root->right=solve2(mid+1,high,inorder);
  return root;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        solve(root,inorder);
int i=0,j=inorder.size()-1;
        TreeNode* node= solve2(i,j,inorder);
        return node;
    }
};