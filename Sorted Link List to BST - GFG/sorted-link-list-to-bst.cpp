// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct LNode
{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

struct TNode  
{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x)
    {
        data=x;
        left=right=NULL;
    }
}; 

void preOrder(TNode* node)  
{  
    if (node == NULL)  
        return;  
    cout<<node->data<<" ";  
    preOrder(node->left);  
    preOrder(node->right);  
} 


 // } Driver Code Ends
//User function Template for C++
//User function Template for C++
/* 
//Linked List
struct LNode{
    int data;
    struct LNode* next;
    
    LNode(int x){
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode{  
    
    int data;  
    struct TNode* left;  
    struct TNode* right; 
    TNode(int x){
        data=x;
        left=right=NULL;
    }
}; */
class Solution{
  public:
    TNode* bstFromLL(LNode *head,LNode *tail){
        if(head==tail){
            return NULL;
        }
        LNode *slow=head,*fast=head;
        while(fast!=tail && fast->next!=tail){
            fast=fast->next->next;
            slow=slow->next;
        }
        TNode *tree=new TNode(slow->data);
        tree->left=bstFromLL(head,slow);
        tree->right=bstFromLL(slow->next,tail);
        return tree;
    }
    TNode* sortedListToBST(LNode *head){
        TNode *tree=bstFromLL(head,NULL);
        return tree;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        LNode *head = new LNode(data);
        LNode *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new LNode(data);
            tail = tail->next;
        }
        Solution ob;
        TNode* Thead = ob.sortedListToBST(head);
        preOrder(Thead);
        cout<<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends