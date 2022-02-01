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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
        ListNode *prev=head;
        ListNode*t=head->next;
        while(t){
            if(t->val==val){
                t=t->next;
                continue;
            }
            prev->next=t;
            prev=t;
            t=t->next;
        }
        prev->next=t;
        return head->val==val?head->next:head;;
    }
};