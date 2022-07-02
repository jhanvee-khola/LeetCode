/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    int findRand(vector<pair<Node*,Node*>> ll,Node *nrand){
        for(int i=0;i<ll.size();i++){
            if(ll[i].first==nrand){
                return i;
            }
        }
        return -1;
    }
    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        vector<pair<Node*,Node*>> ll;
        Node *newHead=new Node(head->val);
        ll.push_back({head,newHead});
        Node *temp=head->next;
        int i=0;
        while(temp){
            Node *n=new Node(temp->val);
            ll.push_back({temp,n});
            ll[i].second->next=n;
            temp=temp->next;
            i++;
        }
        for(int i=0;i<ll.size();i++){
            int ind=findRand(ll,ll[i].first->random);
            if(ind==-1){
                ll[i].second->random=NULL;
            }
            else{
                ll[i].second->random=ll[ind].second;
            }
        }
        return newHead;
    }
};