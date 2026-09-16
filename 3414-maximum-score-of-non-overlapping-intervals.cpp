class Solution {
public:
    class Score_Node {
    public:
        long long score = -1;
        vector<int> indices_taken;
    };
    int findNext(int endpoint, vector<vector<int>>& intervals, int n) {
        int low = 0, high = n - 1, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (intervals[mid][0] > endpoint) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    Score_Node f(int ind, int k, vector<vector<int>>& intervals,
                 vector<int>& next_intervals, int n,
                 vector<vector<Score_Node>>& dp) {
        if (ind == n || k == 0) {
            return Score_Node();
        }
        if (dp[ind][k].score != -1) {
            return dp[ind][k];
        }
        // skip cur interval
        Score_Node skip = f(ind + 1, k, intervals, next_intervals, n, dp);

        // take cur interval
        int original_index = intervals[ind][3];
        int next_idx = next_intervals[ind];
        Score_Node take = f(next_idx, k - 1, intervals, next_intervals, n, dp);

        take.score = intervals[ind][2] + take.score;
        take.indices_taken.push_back(original_index);
        sort(begin(take.indices_taken), end(take.indices_taken));

        Score_Node max_ans;
        if (skip.score > take.score) {
            max_ans = skip;
        } else if (skip.score < take.score) {
            max_ans = take;
        } else {
            max_ans = skip.indices_taken < take.indices_taken ? skip : take;
        }
        return dp[ind][k] = max_ans;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        vector<int> next_intervals(n);
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++) {
            int cur_end = intervals[i][1];
            next_intervals[i] = findNext(cur_end, intervals, n);
            /*
            for (int j = i + 1; j < n; j++) {
                if (intervals[j][0] > cur_end) {
                    next_intervals[i] = j;
                    break;
                }
            }
            */
        }
        vector<vector<Score_Node>> dp(n + 1, vector<Score_Node>(5));
        int ind = 0, k = 4;
        Score_Node ans_node = f(ind, k, intervals, next_intervals, n, dp);
        return ans_node.indices_taken;
    }
};