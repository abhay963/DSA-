/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>nums;
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=lists.size();
        for(auto& it:lists){
         while(it!=NULL){
          pq.push(it->val);
          it=it->next;
         }
        }

        ListNode* dummyNode=new ListNode(-1);
        ListNode* head=dummyNode;

        while(!pq.empty()){
        ListNode* newnode=new ListNode(pq.top());
        pq.pop();
        head->next=newnode;
        head=head->next;
        }

        return dummyNode->next;
    }
};