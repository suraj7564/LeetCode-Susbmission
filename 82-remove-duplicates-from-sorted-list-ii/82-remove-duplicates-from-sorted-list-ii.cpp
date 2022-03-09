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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        map<int,int> m;
        ListNode* t= head;
        while(t){
            m[t->val]++;
            t=t->next;
        }
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        for(auto x:m){
            if(x.second==1){
                ListNode* cur = new ListNode(x.first);
                temp->next=cur;
                temp = temp->next;
            }
        }
        return ans->next;
    }
};