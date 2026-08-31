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
        vector<int> ans(2,INT_MAX); // To store the positions of critical points
        int firstCP = -1, lastCP = -1, curPos = 0;

        ListNode *prevNode = head, *curNode = head->next;
        ListNode* nextNode = curNode->next;

        while (nextNode) {
            // Check if current node is a local maxima or minima
            if ((prevNode->val > curNode->val &&
                 curNode->val < nextNode->val) ||
                (prevNode->val < curNode->val &&
                 curNode->val > nextNode->val)) {
                if (firstCP == -1) {
                    firstCP = curPos;
                    lastCP = curPos;
                } else {
                    ans[0] = min(ans[0], curPos - lastCP);
                    ans[1] = curPos - firstCP;
                    lastCP = curPos;
                }
            }
            curPos++;
            nextNode = nextNode->next;
            curNode = curNode->next;
            prevNode = prevNode->next;
        }
        if (ans[0] == INT_MAX)
            ans[0] = ans[1] = -1;

        return ans;
    }
};