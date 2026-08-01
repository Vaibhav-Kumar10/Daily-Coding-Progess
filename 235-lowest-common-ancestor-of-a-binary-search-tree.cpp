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
        if (root == NULL) {
            return NULL;
        }
        // root larger than both => LCA on left
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // root smaller than both => LCA on right
        else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        // root is one of them, or both are on opposite child
        return root;
    }
    /*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while (node != NULL) {
            // Node larger than both => LCA on left
            if (node->val > p->val && node->val > q->val) {
                node = node->left;
            }
            // Node smaller than both => LCA on right
            else if (node->val < p->val && node->val < q->val) {
                node = node->right;
            }
            // Node is one of them, or both are on opposite child
            else {
                break;
            }
        }
        return node;
    }
    */
};