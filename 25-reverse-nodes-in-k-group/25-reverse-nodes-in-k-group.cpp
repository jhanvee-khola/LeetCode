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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //length
        ListNode *temp1=head;
        int l=0;
        while(temp1!=NULL){
            l++;
            temp1=temp1->next;
        }
        int t=l/k;
        ListNode *ini,*prev=NULL,*curr=head,*temp,*temp2,*ansHead;
        for(int i=0;i<t;i++){
            int j=0;
            ini=prev;
            while(j<k){
                if(j==0){
                    temp=curr->next;
                    curr->next=NULL;
                    prev=curr;
                    curr=temp;
                }
                else{
                    temp=curr->next;
                    curr->next=prev;
                    prev=curr;
                    curr=temp;
                }
                j++;
            }
            if(i==0){
                ansHead=prev;
            }
            temp2=prev;
            while(prev->next!=NULL){
                prev=prev->next;
            }
            if(ini!=NULL){
                ini->next=temp2;
            }
        }
        if(l%k!=0){
            prev->next=curr;
        }
        return ansHead;
    }
};