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
    bool f(TreeNode* root, long long lower_limit, long long upper_limit) {
        if (root == NULL) {
            return true;
        }
        if (root->val <= lower_limit || root->val >= upper_limit) {
            return false;
        }
        bool valid_left = f(root->left, lower_limit, root->val);
        bool valid_right = f(root->right, root->val, upper_limit);
        return valid_left && valid_right;
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        return f(root, LLONG_MIN, LLONG_MAX);
    }
};