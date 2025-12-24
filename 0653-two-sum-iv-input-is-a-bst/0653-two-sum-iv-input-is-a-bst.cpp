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
void fill(TreeNode* root,vector<int>& inorder){
  if(root==NULL)return ;
  fill(root->left,inorder);
  inorder.push_back(root->val);
  fill(root->right,inorder);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        fill(root,inorder);
        unordered_set<int>mp;
        for(int i=0;i<inorder.size();i++){
          int need=k-inorder[i];
          if(mp.find(need)!=mp.end())return true;
         mp.insert(inorder[i]);
        }
        return false;
    }
};