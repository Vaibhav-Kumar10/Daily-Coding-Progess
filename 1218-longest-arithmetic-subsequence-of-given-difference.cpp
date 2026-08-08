class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), ans = 1;
        unordered_map<int, int> prevOcc;
        for(int i = 0; i < n; i++) {
            int req = arr[i] - difference, cnt = 1;
            if(prevOcc.find(req) != prevOcc.end()) {
                cnt += prevOcc[req];
            }
            prevOcc[arr[i]] = cnt;
            ans = max(ans, cnt);
        }
        return ans;
    }
};