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
    ListNode* reverse(ListNode *head){
        ListNode *curr=head,*prev=NULL,*temp;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *second=head;
        right--;
        while(right){
            second=second->next;
            right--;
        }
        ListNode *tail=second->next;
        second->next=NULL;
        
        ListNode *newHead,*revTail;
        ListNode* first=head;
        if(left==1){
            revTail=first;
            newHead=reverse(revTail);
            revTail->next=tail;
        }
        else{
            left-=2;
            while(left>0){
                first=first->next;
                left--;
            }
            revTail=first->next;
            first->next=reverse(revTail);
            revTail->next=tail;
            newHead=head;
        }
        return newHead;
    }
};