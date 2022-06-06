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
    ListNode* midLL(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode *fast=head->next,*slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverseLL(ListNode* head){
        if(!head || !head->next){
            return head;
        }
        ListNode *rHead=reverseLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return rHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *mid=midLL(head);
        mid->next=reverseLL(mid->next);
        ListNode *p1=head,*p2=mid->next;
        while(p2){
            if(p2->val!=p1->val){
                return false;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return true;
    }
};