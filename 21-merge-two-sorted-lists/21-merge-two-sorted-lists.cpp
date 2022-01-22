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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *Temp = new ListNode(-1);
        ListNode *temp = Temp;
        int x;
        while(l1&&l2){
            if(l1->val<=l2->val){
                x=l1->val;
                l1=l1->next;
            }
            else{
                x=l2->val;
                l2=l2->next;
            }
            ListNode* t = new ListNode(x);
            Temp->next=t;
            Temp = Temp->next;
        }
        while(l1){
            ListNode* t = new ListNode(l1->val);
            l1=l1->next;
            Temp->next=t;
            Temp = Temp->next;
        }
        while(l2){
            ListNode* t = new ListNode(l2->val);
            l2=l2->next;
            Temp->next=t;
            Temp = Temp->next;
        }
        return temp->next;
    }
};