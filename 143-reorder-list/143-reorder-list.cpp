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
    void reorderList(ListNode* head) {
        ListNode *first=head,*second=head;
        second=second->next;
        while(second!=NULL && second->next!=NULL){
            first=first->next;
            second=second->next->next;
        }
        ListNode *part2=first->next;
        first->next=NULL;
        ListNode *temp,*prev=NULL;
        while(part2!=NULL){
            temp=part2->next;
            part2->next=prev;
            prev=part2;
            part2=temp;
        }
        part2=prev;
        ListNode *part1=head->next;
        bool f=0;
        ListNode *newHead=head,*ans=head;
        while(part1 || part2){
            if(f){
                newHead->next=part1;
                part1=part1->next;
                f=0;
            }
            else{
                newHead->next=part2;
                part2=part2->next;
                f=1;
            }
            newHead=newHead->next;
        }
        head=ans;
    }
};