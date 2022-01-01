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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        while(head && head->val==val){
            head=head->next;
        }
        if(head==NULL){
            return head;
        }
        ListNode *temp1=head->next,*temp2=head;
        while(temp1!=NULL){
            if(temp1->val==val){
                temp2->next=temp2->next->next;
                temp1=temp1->next;
            }
            else{
                temp1=temp1->next;
                temp2=temp2->next; 
            }
        }
        return head;
    }
};