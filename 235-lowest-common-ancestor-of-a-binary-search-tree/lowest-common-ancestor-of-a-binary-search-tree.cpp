/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if (p->val < root->val && q->val < root->val)
        //     return lowestCommonAncestor(root->left, p, q);
        // if (p->val > root->val && q->val > root->val)
        //     return lowestCommonAncestor(root->right, p, q);
        // return root;
        const int pv = p->val, qv = q->val;
        while(true)
        {
            const int rv = root->val;
            if(pv < rv && qv < rv) root = root->left; 
            else if(pv > rv && qv > rv) root = root->right;
            else return root;
        }
    }
};