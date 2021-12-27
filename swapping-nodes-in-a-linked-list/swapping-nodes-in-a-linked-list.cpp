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
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *start=head,*end=head;
        for(int i=1;i<k;i++){
            start=start->next;
        }
        ListNode* a=start;
        start=start->next;
        while(start){
            start=start->next;
            end=end->next;
        }
        swap(a->val,end->val);
        return head;
    }
};