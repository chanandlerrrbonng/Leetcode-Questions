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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;
        Node* dummy=new Node(-1);
        Node* curr=head;
        Node* prev=dummy;
        while(curr){
            Node* newdummy=new Node(curr->val);
            mp[curr]=newdummy;
            curr=curr->next;
        }
        curr=head;
        while(curr){
            auto it=mp.find(curr);
            prev->next=it->second;
            Node* findnode=it->first->random;
            if(findnode){
            auto it2=mp.find(findnode);
            it->second->random=it2->second;
            }
            else it->second->random=NULL;
            prev=it->second;
            curr=curr->next;

        }
        return dummy->next;
        
    }
};