/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* clone(Node *node,unordered_map<Node*,Node*> &u){
        vector<Node*> neigh;
        Node *n=new Node(node->val);
        u[node]=n;
        for(auto i:node->neighbors){
            if(u.find(i)!=u.end()){
                neigh.push_back(u[i]);
            }
            else{
                neigh.push_back(clone(i,u));
            }
        }
        n->neighbors=neigh;
        return n;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> u;
        if(!node){
            return NULL;
        }
        if(node->neighbors.size()==0){
            Node* n=new Node(node->val);
            return n; 
        }
        return clone(node,u);
    }
};