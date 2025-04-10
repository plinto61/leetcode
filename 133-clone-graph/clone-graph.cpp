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
    unordered_map<int, Node*> mp;

public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        Node* newNode = new Node(node->val);
        mp[node->val] = newNode;

        for (auto n : node->neighbors) {
            auto mpn = mp.find(n->val);
            if (mpn == mp.end()) {
                // mpn = &cloneGraph(n);
                Node* newNeighbour = cloneGraph(n);
                (newNode->neighbors).push_back(newNeighbour);
            } else {
                (newNode->neighbors).push_back(mpn->second);
            }
        }
        return newNode;
    }
};