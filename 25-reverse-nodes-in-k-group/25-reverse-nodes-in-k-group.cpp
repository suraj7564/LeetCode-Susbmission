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
    int lengthOfLinkedList(ListNode* head){
        ListNode* t = head;
        int len = 0;
        while(t){
            len++;
            t = t->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL||head->next == NULL) return head;
    
        int length = lengthOfLinkedList(head);

        ListNode* dummyNode = new ListNode(0);
        
        dummyNode->next = head;
        
        ListNode*pre = dummyNode,*cur,*nxt;
        
        while(length>=k){
            cur = pre->next;
            nxt = cur->next;
            int p = k-1;
            while(cur&&p-->0){
                cur->next = nxt->next;
                nxt->next = pre->next;
                pre->next = nxt;
                nxt = cur->next;
            }
            pre = cur;
            length-=k;
        }
        return dummyNode->next;
    }
};