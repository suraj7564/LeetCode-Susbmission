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
        ListNode *temp1 = headA;
        map<ListNode*,int> m;
        while(temp1){
            m[temp1]++;
            temp1 = temp1 -> next;
        }
        ListNode *temp2 = headB;
        while(temp2){
            if(m.count(temp2)){
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;
    }
};