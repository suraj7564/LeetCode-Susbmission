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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return head;
        ListNode *pre=head;
        ListNode *t=head->next;
        ListNode *cur;
        while(t){
            if(pre->val==t->val){
                while(t&&pre->val==t->val){
                    t=t->next;
                }
                pre->next=t;
                pre=t;
                if(t){
                    t=t->next;
                }
            }
            else{
                pre=t;
                t=t->next;
            }
        }
        return head;
    }
};