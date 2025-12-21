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
void fillparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parentMp){
  queue<TreeNode*>q;
  q.push(root);
  while(!q.empty()){
    int size=q.size();
    for(int i=0;i<size;i++){
      TreeNode* node=q.front();
      q.pop();
      if(node->left){
        q.push(node->left);
        parentMp[node->left]=node;
      }
      if(node->right){
        q.push(node->right);
        parentMp[node->right]=node;
      }
    }
  }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentMp;
        vector<int>ans;
        if(root==NULL)return ans;
          fillparent(root,parentMp);
          unordered_map<TreeNode*,bool>vis;
          queue<TreeNode*>q;
          q.push(target);
          int dis=0;
          vis[target]=true;
          while(!q.empty()){
            int size=q.size();
            if(dis==k)break;
            dis++;
            for(int i=0;i<size;i++){
              TreeNode* node=q.front();
              q.pop();
              if(node->left && !vis[node->left]){
                  q.push(node->left);
                  vis[node->left]=true;
              }

              if(node->right && !vis[node->right]){
                q.push(node->right);
                vis[node->right]=true;
              }

              if(parentMp[node] && !vis[parentMp[node]]){
                q.push(parentMp[node]);
                vis[parentMp[node]]=true;
              }
            }
          }

          while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
          }
          return ans;
    }
};