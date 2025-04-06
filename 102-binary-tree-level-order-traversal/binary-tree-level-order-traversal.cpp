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
    vector<TreeNode*> getNextLayer(vector<TreeNode*>& layer) {
        vector<TreeNode*> nextLayer;
        for (auto node : layer) {
            if (node->left != nullptr) {
                nextLayer.push_back(node->left);
            }
            if (node->right != nullptr) {
                nextLayer.push_back(node->right);
            }
        }
        return nextLayer;
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        vector<TreeNode*> layer = {root};
        while (layer.size() > 0) {
            vector<int> vals;
            for (auto node : layer) {
                cout << node->val << ", ";
                vals.push_back(node->val);
            }
            cout << endl;
            result.push_back(vals);
            layer = getNextLayer(layer);
        }
        return result;
    }
};