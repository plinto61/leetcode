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

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root)
            return result;
        queue<TreeNode*> layer;
        layer.push(root);
        while (!layer.empty()) {
            vector<int> vals;
            int queueSize = layer.size();
            for (int i = 0; i < queueSize; i++) {
                TreeNode* node = layer.front();
                layer.pop();
                if (node->left)
                    layer.push(node->left);
                if (node->right)
                    layer.push(node->right);
                vals.push_back(node->val);
            }
            result.push_back(vals);
        }
        return result;
    }
};