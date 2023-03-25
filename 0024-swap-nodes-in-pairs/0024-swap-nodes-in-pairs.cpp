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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *ans=head->next;
        ListNode *prev=NULL,*curr=head,*temp;
        while(curr && curr->next){
            temp=curr->next->next;
            curr->next->next=curr;
            if(prev){
                prev->next=curr->next;
            }
            curr->next=temp;
            prev=curr;
            curr=curr->next;
        }
        return ans;
    }
};