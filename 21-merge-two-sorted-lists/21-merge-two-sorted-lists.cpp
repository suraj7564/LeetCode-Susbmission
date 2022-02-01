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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans= new ListNode(-1);
        ListNode *t=ans;
        int x;
        while(list1&&list2){
            if(list1->val<=list2->val){
                x=list1->val;
                list1=list1->next;
            }
            else{
                x=list2->val;
                list2=list2->next;
            }
            ListNode* temp=new ListNode(x);
            t->next=temp;
            t=t->next;
        }
        while(list1){
            x=list1->val;
            list1=list1->next;
            ListNode* temp=new ListNode(x);
            t->next=temp;
            t=t->next;
        }
        while(list2){
            x=list2->val;
            list2=list2->next;
            ListNode* temp=new ListNode(x);
            t->next=temp;
            t=t->next;
        }
        return ans->next;
    }
};