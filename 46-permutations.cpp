class Solution {
public:
    void f(int ind, vector<vector<int>>& ans, vector<int>& arr) {
        if (ind == arr.size()) {
            ans.push_back(arr);
            return;
        }
        for (int i = ind; i < arr.size(); i++) {
            swap(arr[ind], arr[i]);
            // Next index
            f(ind + 1, ans, arr);
            swap(arr[ind], arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        f(0, ans, nums);
        return ans;
    }
    /*
    void f(vector<int>& curPerm, vector<vector<int>>& ans, vector<int>& arr,
           unordered_map<int, int>& freq) {
        if (curPerm.size() == arr.size()) {
            ans.push_back(curPerm);
            return;
        }
        for (int i = 0; i < arr.size(); i++) {
            // Already used
            if (freq.find(arr[i]) != freq.end()) {
                continue;
            }
            curPerm.push_back(arr[i]);
            freq[arr[i]]++;
            f(curPerm, ans, arr, freq);
            freq.erase(arr[i]);
            curPerm.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curPerm;
        unordered_map<int, int> freq;
        f(curPerm, ans, nums, freq);
        return ans;
    }
    */
};