class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        vector<bool> visited(upper + 1, false);
        for (int num : nums) {
            // only taking num that lie b/w [lower, upper]
            if (num >= lower && num <= upper) {
                visited[num] = true;
            }
        }
        /*
        vector<int> cur;
        vector<vector<int>> ans;
        for (int i = lower; i <= upper; i++) {
            if (visited[i] == false) {
                cur.push_back(i);
            } else {
                if (!cur.empty()) {
                    ans.push_back(cur);
                    cur.clear();
                }
            }
        }
        if (!cur.empty()) {
            ans.push_back(cur);
        }
        */
        vector<vector<int>> ans;
        int start_idx, i = lower;
        while (i <= upper) {
            if (visited[i] == false) {
                start_idx = i;
                // until we reach last missing num
                while (i <= upper && visited[i] == false) {
                    i++;
                }
                ans.push_back({start_idx, i - 1});
            } else {
                i++;
            }
        }
        return ans;
    }
};