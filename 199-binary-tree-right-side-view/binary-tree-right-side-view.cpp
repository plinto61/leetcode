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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root)
            return result;
        queue<TreeNode*> layer;
        layer.push(root);
        while(!layer.empty()) {
            int rightMostVal;
            int qSize = layer.size();
            for(int i=0; i<qSize; i++) {
                TreeNode* node = layer.front();
                layer.pop();
                if(node->left) layer.push(node->left);
                if(node->right) layer.push(node->right);
                rightMostVal = node->val;
            }
            result.push_back(rightMostVal);
        }
        return result;
    }
};