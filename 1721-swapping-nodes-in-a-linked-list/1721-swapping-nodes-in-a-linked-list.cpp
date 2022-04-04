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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* t=head;
        ListNode* tt=head;
        if(head==NULL){
            return head;
        }
        int y=1;
        while(temp->next!=NULL){
            
             
            if(y==k){
                break;
            }
            temp=temp->next;
            y++;
           
        }
        int p=1;
        while(t->next!=NULL){
            p++;
            t=t->next;
        }
        int r=(p-k)+1;
        int x=1;
        while(tt->next!=NULL){
            if(x==r){
                break;
            }
            tt=tt->next;
            x++;
            
        }
        //cout<<y<<" "<<r<<endl; 
        int tr=temp->val;
        temp->val=tt->val;
        tt->val=tr;
        return head;
        
    }
};