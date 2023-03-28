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
        int l=0;
        while(temp){
            l++;
            temp=temp->next;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0){
            return head;
        }
        ListNode *fast=head,*slow=head;
        int n=length(head);
        k%=n;
        if(n==1 || k==0){
            return head;
        }
        for(int i=0;i<k;i++){
            fast=fast->next;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *temp=slow->next;
        slow->next=NULL;
        fast->next=head;
        head=temp;
        return head;
    }
};