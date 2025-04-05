/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    bool balanced = true;
private:
    int depth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        balanced = balanced && (abs(left-right) <= 1);
        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        depth(root);
        return balanced;
    }
};