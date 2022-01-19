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
    bool hasCycle(ListNode *head) {
        ListNode* slw=head;
        ListNode* fst=head;
        
        while(slw&&fst&&fst->next){
            slw=slw->next;
            fst=fst->next->next;
            if(fst==slw) return true;
        }
        return false;
    }
};