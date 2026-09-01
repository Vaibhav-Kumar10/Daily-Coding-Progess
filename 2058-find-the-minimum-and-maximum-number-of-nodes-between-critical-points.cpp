/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {INT_MAX, INT_MIN};
        ListNode *prev_node = head, *cur_node = head->next;
        ListNode* next_node = cur_node->next;
        int first_critical_point = -1, last_critical_point = -1, cur_pos = 0;
        while (next_node != NULL) {
            if ((cur_node->val > prev_node->val &&
                 cur_node->val > next_node->val) ||
                (cur_node->val < prev_node->val &&
                 cur_node->val < next_node->val)) {
                if (first_critical_point == -1) {
                    first_critical_point = cur_pos;
                    last_critical_point = cur_pos;
                } else {
                    int min_dist = cur_pos - last_critical_point;
                    int max_dist = cur_pos - first_critical_point;
                    ans[0] = min(ans[0], min_dist);
                    ans[1] = max(ans[1], max_dist);
                    last_critical_point = cur_pos;
                }
            }
            cur_pos++;
            next_node = next_node->next;
            cur_node = cur_node->next;
            prev_node = prev_node->next;
        }
        if (ans[0] == INT_MAX) {
            return {-1, -1};
        }
        return ans;
    }
};