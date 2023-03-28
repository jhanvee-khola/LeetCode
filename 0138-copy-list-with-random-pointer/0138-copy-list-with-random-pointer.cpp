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
        if(!head){
            return head;
        }
        Node *curr=head,*temp;
        while(curr){
            temp=curr->next;
            Node *n=new Node(curr->val);
            curr->next=n;
            n->next=temp;
            curr=temp;
        }
        curr=head;
        while(curr){
            if(curr->random){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        curr=head;
        Node *nhead=head->next,*copy=nhead;
        while(copy->next){
            curr->next=curr->next->next;
            curr=curr->next;
            
            copy->next=copy->next->next;
            copy=copy->next;
        }
        curr->next=curr->next->next;
        return nhead;
    }
};