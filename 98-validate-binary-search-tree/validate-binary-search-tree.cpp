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
private:
    bool valid(TreeNode* node, long minval, long maxval) {
        if (!node)
            return true;
        if (node->val <= minval || node->val >= maxval)
            return false;
        return valid(node->left, minval, node->val) &&
               valid(node->right, node->val, maxval);
    }

public:
    bool isValidBST(TreeNode* root) { return valid(root, LONG_MIN, LONG_MAX); }
};