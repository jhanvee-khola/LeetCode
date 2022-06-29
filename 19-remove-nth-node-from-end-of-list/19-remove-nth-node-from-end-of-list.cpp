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
    int length(ListNode *head){
        ListNode *temp=head;
        int size=0;
        while(temp){
            size++;
            temp=temp->next;
        }
        return size;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=length(head);
        int shift=size-n-1;
        if(shift==-1){
            head=head->next;
            return head;
        }
        ListNode *temp=head;
        while(shift--){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};