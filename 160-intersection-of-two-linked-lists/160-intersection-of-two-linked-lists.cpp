/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode *head){
        ListNode *temp=head;
        int l=0;
        while(temp!=NULL){
            l++;
            temp=temp->next;
        }
        return l;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1=headA,*l2=headB;
        int n=length(l1),m=length(l2);
        if(n>m){
            int k=n-m;
            while(k--){
                l1=l1->next;
            }
        }
        else if(n<m){
            int k=m-n;
            while(k--){
                l2=l2->next;
            }
        }
        while(l1!=NULL && l2!=NULL && l1!=l2){
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==NULL || l2==NULL){
            return NULL;
        }
        return l1;
    }
};