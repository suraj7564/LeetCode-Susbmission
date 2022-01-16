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
    ListNode* middleNode(ListNode* head) {
        ListNode* t=head,*tt=head;
        int x=0;
        while(t!=NULL){
            x++;
            t=t->next;
        }
        int y=x/2;
        while(y-->0){
            tt=tt->next;
        }
        return tt;
    }
};