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
    int f(TreeNode* root, int& cnt) {
        if (root == NULL) {
            return 0;
        }
        cnt++;
        return root->val + f(root->left, cnt) + f(root->right, cnt);
    }
    int ans = 0;
    int averageOfSubtree(TreeNode* root) {
        if (root == NULL) {
            return 1;
        }
        int cnt = 0;
        int child_sum = f(root, cnt);
        int avg = child_sum / cnt;
        if (avg == root->val) {
            ans++;
        }
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return ans;
    }
};