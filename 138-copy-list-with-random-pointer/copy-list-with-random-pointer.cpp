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
        unordered_map<Node*, Node*> mp;
        Node* h = head;
        while(h != nullptr) {
            mp[h] = new Node(h->val);
            h = h->next;
        }
        h = head;
        while(h != nullptr) {
            mp[h]->next = h->next != nullptr ? mp[h->next] : nullptr;
            mp[h]->random = h->random != nullptr ? mp[h->random] : nullptr;
            h = h->next;
        }
        return mp[head];
    }
};