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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        for(auto x:lists){
            ListNode* temp = x;
            while(temp){
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(ans.begin(),ans.end());
        ListNode *res = new ListNode(-1);
        ListNode* t = res;
        for(auto x:ans){
            ListNode *tt = new ListNode(x);
            t->next = tt;
            t = t->next;
        }
        return res->next;
    }
};