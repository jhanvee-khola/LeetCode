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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode(),*l=ans;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int total=0;
            if(l1){
                total+=l1->val;
                l1=l1->next;
            }
            if(l2){
                total+=l2->val;
                l2=l2->next;
            }
            total+=carry;
            carry=total/10;
            total%=10;
            ListNode *temp=new ListNode(total);
            l->next=temp;
            l=l->next;
        }
        return ans->next;
    }
};