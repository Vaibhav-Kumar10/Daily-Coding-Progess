class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
        }
        while (k--) {
            int num = minHeap.top();
            minHeap.pop();
            minHeap.push(-num);
        }
        while (!minHeap.empty()) {
            ans += minHeap.top();
            minHeap.pop();
        }
        return ans;
    }
};