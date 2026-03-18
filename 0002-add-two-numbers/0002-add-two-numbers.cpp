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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode=new ListNode(-1);
        ListNode* head=dummyNode;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
          int val1=0,val2=0;
          if(l1){
            val1+=l1->val;
            l1=l1->next;
          }
          if(l2){
            val2+=l2->val;
            l2=l2->next;
          }

          int val=val1+val2+carry;
          int num=val%10;
          carry=val/10;
          ListNode* newNode=new ListNode(num);
          head->next=newNode;
          head=newNode;
        }
        if(carry!=0){
          ListNode* newNode=new ListNode(carry);
          head->next=newNode;
          head=newNode;
        }
        return dummyNode->next;
    }
};