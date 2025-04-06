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
    int goodNodesCount = 0;
private:
    void checkGoodNode(TreeNode* node, int maxSoFar) {
        int maxVal = max(node->val, maxSoFar);
        if(node->val == maxVal) goodNodesCount++;
        if(node->right) checkGoodNode(node->right, maxVal);
        if(node->left) checkGoodNode(node->left, maxVal);
    }
public:
    int goodNodes(TreeNode* root) {
        checkGoodNode(root, -10000);
        return goodNodesCount;
    }
};