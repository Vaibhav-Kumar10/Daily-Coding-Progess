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
    TreeNode *first_violation = NULL, *last_violation = NULL, *wrt = NULL,
             *prev_node = NULL;
    void inorder_traversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder_traversal(root->left);
        if (prev_node != NULL && (prev_node->val > root->val)) {
            if (first_violation == NULL) {
                first_violation = prev_node;
                wrt = root;
            } else {
                last_violation = root;
            }
        }
        prev_node = root;
        inorder_traversal(root->right);
    }
    void recoverTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder_traversal(root);
        if (first_violation != NULL && last_violation != NULL) {
            swap(first_violation->val, last_violation->val);
        } else if (first_violation != NULL && wrt != NULL) {
            swap(first_violation->val, wrt->val);
        }
    }
};