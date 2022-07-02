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
    ListNode* partition(ListNode* head, int x) {
        ListNode *first=NULL,*second=NULL,*newHead=NULL;
        ListNode *temp=head,*temp1=NULL;
        while(temp){
            if(temp->val<x){
                if(!first){
                    first=temp;
                    newHead=first;
                }
                else{
                    first->next=temp;
                    first=first->next;
                }
            }
            else{
                if(!second){
                    second=temp;
                    temp1=second;
                }
                else{
                    second->next=temp;
                    second=second->next;
                }
            }
            temp=temp->next;
        }
        if(!first){
            newHead=temp1;
        }
        if(second){
            second->next=NULL;
        }
        if(first){
            first->next=temp1;
        }
        return newHead;
    }
};