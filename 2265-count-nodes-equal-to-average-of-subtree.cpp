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
    int ans = 0;
    pair<int, int> f(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }
        pair<int, int> left_data = f(root->left);
        pair<int, int> right_data = f(root->right);
        int child_sum = left_data.first + right_data.first;
        int child_cnt = left_data.second + right_data.second;

        int total_sum = child_sum + root->val, total_cnt = child_cnt + 1;
        int avg = total_sum / total_cnt;
        if (avg == root->val) {
            ans++;
        }
        return {total_sum, total_cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        f(root);
        return ans;
    }
    /*
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
    */
};