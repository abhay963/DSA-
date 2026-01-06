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
int sum=0;
void solve(TreeNode* root,string& path){
  if(root==NULL)return;
  path+=to_string(root->val);
  if(root->left==NULL && root->right==NULL){
    sum+=stoi(path);
    path.pop_back();
    return;
  }

  if(root->left) solve(root->left,path);
  if(root->right) solve(root->right,path);
  path.pop_back();
  return;
}
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return 0;
        string path="";
        solve(root,path);
        return sum;
    }
};