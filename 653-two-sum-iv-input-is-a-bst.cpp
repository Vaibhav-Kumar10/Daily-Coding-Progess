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
class BSTIterator {
public:
    stack<TreeNode*> st_n, st_b;
    BSTIterator(TreeNode* root) {
        TreeNode *root_left = root, *root_right = root;
        while (root_right != NULL) {
            st_b.push(root_right);
            root_right = root_right->right;
        }
        while (root_left != NULL) {
            st_n.push(root_left);
            root_left = root_left->left;
        }
    }
    int next() {
        TreeNode* top_node = st_n.top();
        st_n.pop();
        TreeNode* right_node = top_node->right;
        while (right_node != NULL) {
            st_n.push(right_node);
            right_node = right_node->left;
        }
        return top_node->val;
    }
    int before() {
        TreeNode* top_node = st_b.top();
        st_b.pop();
        TreeNode* left_node = top_node->left;
        while (left_node != NULL) {
            st_b.push(left_node);
            left_node = left_node->right;
        }
        return top_node->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator* bst = new BSTIterator(root);
        int l = bst->next(), r = bst->before();
        while (l < r) {
            int sum = l + r;
            if (sum == k) {
                return true;
            } else if (sum < k) {
                l = bst->next();
            } else {
                r = bst->before();
            }
        }
        return false;
    }
};