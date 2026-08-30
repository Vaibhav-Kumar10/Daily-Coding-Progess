class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<int> prev(sum + 1, INT_MAX);
        // sum = 0 is always possible
        prev[0] = 0;
        for (int num : nums) {
            // num => num * 2
            // num => num * 2
            // .
            // .
            // .
            // num => num / 2;
            // num => num / 2;
            // num E [1, sum]
            // try all possible ops
            vector<pair<int, int>> possible_ops;
            int x = num, ops = 0;
            possible_ops.push_back({x, ops});
            // multiply first
            while (x * 2 <= sum) {
                x *= 2;
                ops++;
                possible_ops.push_back({x, ops});
            }
            // then divides
            x = num, ops = 0;
            while (x > 0) {
                x /= 2;
                ops++;
                possible_ops.push_back({x, ops});
            }

            // use dp to find the best suitable selection
            vector<int> cur = prev;
            for (auto [cur_val, ops] : possible_ops) {
                // check for each sum possible
                for (int s = 0; s + cur_val <= sum; s++) {
                    // not possible
                    if (prev[s] == INT_MAX) {
                        continue;
                    }
                    // possible
                    // take or not take
                    cur[s + cur_val] = min(prev[s] + ops, cur[s + cur_val]);
                }
            }
            prev = cur;
        }
        // not possible
        if (prev[sum] == INT_MAX) {
            return -1;
        }
        return prev[sum];
    }
};