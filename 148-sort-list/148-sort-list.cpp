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
    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        ListNode* t=head;
        while(t){
            ans.push_back(t->val);
            t=t->next;
        }
        sort(ans.begin(),ans.end());
        ListNode* dumy= new ListNode(-1);
        ListNode* temp=dumy;
        for(auto x:ans){
            ListNode* tt=new ListNode(x);
            temp->next=tt;
            temp=temp->next;
        }
        head = dumy->next;
        return head;
    }
};