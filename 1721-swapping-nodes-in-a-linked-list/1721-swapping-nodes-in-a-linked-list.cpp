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
        ListNode *first=head,*second=head;
        k--;
        for(int i=0;i<k;i++){
            first=first->next;
        }
        int val1=first->val;
        ListNode *temp=first;
        while(first->next){
            first=first->next;
            second=second->next;
        }
        temp->val=second->val;
        second->val=val1;
        
        return head;
    }
};