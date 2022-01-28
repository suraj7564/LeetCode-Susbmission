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
        unordered_map<ListNode*,int> m;
        ListNode* t=headA;
        while(t){
            m[t]=1;
            t=t->next;
        }
        ListNode* temp=headB;
        while(temp){
            if(m.count(temp)){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
};