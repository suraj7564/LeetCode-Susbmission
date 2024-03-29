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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy;
        for(int i=1;i<left;i++){
            pre = pre->next;
        }
        ListNode *cur, *nxt;
        int sz = right-left+1;
        if(sz>1){
            cur = pre->next;
            nxt = cur->next;
            for(int i=1;i<sz;i++){
                cur->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = cur->next;
            }
            pre = cur;
        }
        return dummy->next;    
    }
};