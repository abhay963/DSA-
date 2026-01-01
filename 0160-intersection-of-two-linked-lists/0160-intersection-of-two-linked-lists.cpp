/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1=0,cnt2=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL){
          cnt1++;
          temp1=temp1->next;
        }

        while(temp2!=NULL){
          cnt2++;
          temp2=temp2->next;

        }

        int diff=abs(cnt1-cnt2);
        temp1=headA;
        temp2=headB;
        if(cnt1>cnt2){
          while(diff!=0){
            temp1=temp1->next;
            diff--;
          }
        }
        else{
          while(diff!=0){
            temp2=temp2->next;
            diff--;
          }
        }

        while(temp1!=NULL && temp2!=NULL){
          if(temp1==temp2)return temp1;
          temp1=temp1->next;
          temp2=temp2->next;
        }

        return NULL;
    }
};