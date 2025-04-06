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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        bool rootFound = false;
        vector<int> left_inorder, right_inorder;
        for(int v : inorder) {
            if(v != preorder[0]) {
                if(rootFound) {
                    right_inorder.push_back(v);
                } else {
                    left_inorder.push_back(v);
                }
            } else {
                rootFound = true;
            }
        }
        vector<int> left_preorder, right_preorder; 
        for(int i=1; i<preorder.size(); i++) {
            if(left_preorder.size() < left_inorder.size()) {
                left_preorder.push_back(preorder[i]);
            } else {
                right_preorder.push_back(preorder[i]);
            }
        }
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }
};

/*
Preorder: [3,9,20,15,7]
Inorder:  [9,3,15,20,7]

Preorder: [1,2,3,4]
Inorder:  [4,3,2,1]

Preorder: [1,2,3,4]
Inorder:  [1,2,3,4]

Preorder: [1]
Inorder:  [1]

Preorder: []
Inorder:  []

Preorder: [1,2,4,5,3,6,7]
Inorder:  [4,2,5,1,6,3,7]

    1
 2     3
4 5   6 7

Preorder: [5,3,2,4,8,7,9]
Inorder:  [2,3,4,5,7,8,9]
    5
 3     8
2 4   7 9
Preorder: [10,6,4,8,14,12,16]
Inorder:  [4,6,8,10,12,14,16]

Preorder: [1,2,5,3,6,7]
Inorder:  [5,2,1,6,3,7]

Preorder: [8,5,1,7,10,12]
Inorder:  [1,5,7,8,10,12]

*/