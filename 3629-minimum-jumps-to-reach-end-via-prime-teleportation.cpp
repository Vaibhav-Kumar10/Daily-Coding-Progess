class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size(), maxNum = *max_element(nums.begin(), nums.end());
        if (n == 1) {
            return 0;
        }
        vector<bool> visited(n, false), isPrime(maxNum + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int num = 2; num * num <= maxNum; num++) {
            if (isPrime[num]) {
                for (int i = num * 2; i <= maxNum; i += num) {
                    isPrime[i] = false;
                }
            }
        }
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < n; i++) {
            indices[nums[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0] = true;
        unordered_set<int> visited_primes;
        while (!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();
            if (cur == n - 1) {
                return steps;
            }
            if (cur - 1 >= 0 && !visited[cur - 1]) {
                q.push({cur - 1, steps + 1});
                visited[cur - 1] = true;
            }
            if (cur + 1 < n && !visited[cur + 1]) {
                q.push({cur + 1, steps + 1});
                visited[cur + 1] = true;
            }
            if (!isPrime[nums[cur]] ||
                visited_primes.find(nums[cur]) != visited_primes.end()) {
                continue;
            }
            visited_primes.insert(nums[cur]);
            for (int multiple = nums[cur]; multiple <= maxNum;
                 multiple += nums[cur]) {
                if (indices.find(multiple) == indices.end()) {
                    continue;
                }
                for (int j : indices[multiple]) {
                    if (!visited[j] && j != cur && nums[j] % nums[cur] == 0) {
                        q.push({j, steps + 1});
                        visited[j] = true;
                    }
                }
            }
        }
        return -1;
    }
};