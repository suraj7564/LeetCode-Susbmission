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
        vector<int> ans;
        ListNode *t = head;
        while(t){
            ans.push_back(t->val);
            t=t->next;
        }
        left--;
        reverse(ans.begin()+left,ans.begin()+right);
        ListNode* result = new ListNode(-1);
        ListNode* tp = result;
        for(auto x:ans){
            ListNode* tt = new ListNode(x);
            tp->next = tt;
            tp = tp->next;
        }
        return result->next;
    }
};