/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node *temp = head;
        while(temp){
            Node *cur = new Node(temp->val);
            Node *nxt = temp->next;
            cur -> next = nxt;
            temp->next = cur;
            temp = cur -> next;
        }
        temp = head;
        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        Node *ans = head->next;
        Node *res = ans;
        while(head){
            head->next = res->next;
            head = head->next;
            if(!head) break;
            res -> next = head->next;
            res = res->next;
        }
        return ans;
    }
};