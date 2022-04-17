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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        if(!head) return head;
        ListNode* temp = head;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }
        int st = n-k+1;
        int x = 1;
        ListNode* t = head;
        ListNode* pre = NULL;
        if(st==1) return head->next;

        while(x<st){
            x++;
            pre = t;
            t=t->next;
        }
        if(!t){
            pre->next = NULL;
            return head;
        }
        pre->next = t->next;
        return head;
    }
};