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
void solve(TreeNode* root,vector<int>& ans,vector<int>& ds,int level){
  if(root==NULL)return ;
  if(ans.size()==level)ans.push_back(root->val);
  
  solve(root->right,ans,ds,level+1);
  solve(root->left,ans,ds,level+1);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)return ans;
        vector<int>ds;
      
        solve(root,ans,ds,0);
        return ans;
    }
};