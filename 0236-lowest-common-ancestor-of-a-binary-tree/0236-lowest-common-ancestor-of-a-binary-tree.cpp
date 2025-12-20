/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool solve(TreeNode* root,int x,vector<int>& arr){
  if(root==NULL)return false;
  arr.push_back(root->val);
  if(root->val==x)return true;
  if(solve(root->left,x,arr)||solve(root->right,x,arr))return true;
  arr.pop_back();
  return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return root;
        vector<int>arr1;
        vector<int>arr2;
        solve(root,p->val,arr1);
        solve(root,q->val,arr2);
        int val1=0;
        for(int i=0;i<min(arr1.size(),arr2.size());i++){
          if(arr1[i]==arr2[i])val1=arr1[i];
        }
        TreeNode* node=new TreeNode(val1);
        return node;
    }
};