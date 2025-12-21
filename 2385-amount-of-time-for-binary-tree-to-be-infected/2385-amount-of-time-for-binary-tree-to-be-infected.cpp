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
TreeNode* findtarget(int start,TreeNode* root){
  queue<TreeNode*>q;
  q.push(root);
  while(!q.empty()){
    int size=q.size();
    for(int i=0;i<size;i++){
      TreeNode* node=q.front();
      q.pop();
      if(node->val==start)return node;
      if(node->left)q.push(node->left);
      if(node->right)q.push(node->right);
    }
  }
  return NULL;
}
void findpar(unordered_map<TreeNode*,TreeNode*>& parMp,TreeNode*& root){
  if(root==NULL)return ;
  queue<TreeNode*>q;
  q.push(root);
  while(!q.empty()){
    int size=q.size();
    for(int i=0;i<size;i++){
      TreeNode* node=q.front();
      q.pop();
      if(node->left){
        parMp[node->left]=node;
        q.push(node->left);
      }

      if(node->right){
        parMp[node->right]=node;
        q.push(node->right);
      }
    }
  }
}
    int amountOfTime(TreeNode* root, int start) {
        int ans=0;
        if(root==NULL)return ans;
        TreeNode* target=findtarget(start,root);
        if(target==NULL)return ans;

        unordered_map<TreeNode*,TreeNode*>par;
        findpar(par,root);

        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        q.push(target);
        while(!q.empty()){
          int size=q.size();
          ans++;
          for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();

            if(node->left && !vis[node->left]){
              vis[node->left]=true;
              q.push(node->left);
            }

            if(node->right && !vis[node->right]){
              vis[node->right]=true;
              q.push(node->right);
            }

            if(par[node] && !vis[par[node]]){
              vis[par[node]]=true;
              q.push(par[node]);
            }
          }
        }
        return ans-1;
    }
};