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
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
        }
        if(pq.empty()){
            return NULL;
        }
        ListNode *ans=pq.top();
        pq.pop();
        if(ans->next){
            pq.push(ans->next);
        }
        ListNode *tail=ans;
        while(!pq.empty()){
            tail->next=pq.top();
            pq.pop();
            tail=tail->next;
            if(tail->next){
                pq.push(tail->next);
            }
        }
        return ans;
    }
};