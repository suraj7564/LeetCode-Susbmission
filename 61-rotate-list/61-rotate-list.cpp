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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next) return head;
        int len = 0;
        ListNode *temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        k = k%len;
        if(k==0) return head;
        k = len-k;
        ListNode *t = head,*pre;
        while(k>0){
            k--;
            pre = t;
            t = t->next;
        }
        pre->next = NULL;
        temp = t;
        while(temp->next){
            temp = temp->next;
        }
        temp -> next = head;
        return t;
    }
};