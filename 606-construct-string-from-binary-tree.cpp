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
    void preorder(TreeNode* root, string& ans) {
        if (root == NULL) {
            return;
        }
        ans += to_string(root->val);
        TreeNode* left_child = root->left;
        TreeNode* right_child = root->right;
        if (left_child != NULL) {
            ans += '(';
            preorder(left_child, ans);
            ans += ')';
        }
        if (right_child != NULL) {
            if (left_child == NULL) {
                ans += "()";
            }
            ans += '(';
            preorder(right_child, ans);
            ans += ')';
        }
    }
    string tree2str(TreeNode* root) {
        string ans = "";
        preorder(root, ans);
        return ans;
    }
};