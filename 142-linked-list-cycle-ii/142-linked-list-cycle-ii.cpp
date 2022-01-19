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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool> m;
        ListNode* t=head;
        while(t!=NULL){
            if(m.find(t)==m.end()){
                m[t]=true;
            }
            else return t;
            t=t->next;
        }
        return NULL;
    }
};