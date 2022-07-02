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
    int length(ListNode *head){
        int count=0;
        ListNode *temp=head;
        while(temp){
            temp=temp->next;
            count++;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> llInPart;
        int l=length(head);
        int n=l/k-1,rem=l%k;
        ListNode *temp=head;
        while(k--){
            if(!temp){
                llInPart.push_back(temp);
                continue;
            }
            ListNode *part=temp;
            for(int i=0;i<n;i++){
                temp=temp->next;
            }
            if(rem && n>=0){
                temp=temp->next;
                rem--;
            }
            if(!temp){
                llInPart.push_back(part);
                continue;
            }
            ListNode *newTemp=temp->next;
            temp->next=NULL;
            llInPart.push_back(part);
            temp=newTemp;
        }
        return llInPart;
    }
};