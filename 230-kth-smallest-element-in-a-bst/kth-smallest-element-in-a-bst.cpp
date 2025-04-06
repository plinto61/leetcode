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
public:
    int kthSmallest(TreeNode* root, int k) {
        if(breakLoop) return kthNodeVal;
        if(!root) return kthNodeVal;
        kthSmallest(root->left, k);
        nodeCount++;
        if(nodeCount == k) {
            breakLoop = true;
            kthNodeVal = root->val;
            return kthNodeVal;
        }
        kthSmallest(root->right, k);
        return kthNodeVal;
    }
};