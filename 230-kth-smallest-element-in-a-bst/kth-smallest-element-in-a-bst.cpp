/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int nodeCount = 0;
    bool breakLoop = false;
    int kthNodeVal;
private:
    void traverseGraph(TreeNode* node, int k) {
        if(breakLoop || !node) return;
        traverseGraph(node->left, k);
        nodeCount++;
        if(nodeCount == k) {
            breakLoop = true;
            kthNodeVal = node->val;
            return;
        }
        traverseGraph(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        traverseGraph(root, k);
        return kthNodeVal;
    }
};