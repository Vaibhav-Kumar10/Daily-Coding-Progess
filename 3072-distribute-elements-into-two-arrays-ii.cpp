class Solution {
public:
    /*
    int greaterCount(vector<int>& a, int num) {
        int cnt = 0;
        for (int el : a) {
            if (el > num) {
                cnt++;
            }
        }
        return cnt;
    }
    */
    int greaterCount(vector<int>& a, int num) {
        return a.end() - upper_bound(a.begin(), a.end(), num);
    }

    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2, s_a1, s_a2;
        int n = nums.size();
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        s_a1.push_back(nums[0]);
        s_a2.push_back(nums[1]);

        for (int i = 2; i < n; i++) {
            int gc_a1 = greaterCount(s_a1, nums[i]);
            int gc_a2 = greaterCount(s_a2, nums[i]);
            if (gc_a1 > gc_a2) {
                auto it = lower_bound(s_a1.begin(), s_a1.end(), nums[i]);
                s_a1.insert(it, nums[i]);
                arr1.push_back(nums[i]);
            } else if (gc_a1 < gc_a2) {
                auto it = lower_bound(s_a2.begin(), s_a2.end(), nums[i]);
                s_a2.insert(it, nums[i]);
                arr2.push_back(nums[i]);
            } else {
                if (arr1.size() < arr2.size()) {
                    auto it = lower_bound(s_a1.begin(), s_a1.end(), nums[i]);
                    s_a1.insert(it, nums[i]);
                    arr1.push_back(nums[i]);
                } else if (arr1.size() > arr2.size()) {
                    auto it = lower_bound(s_a2.begin(), s_a2.end(), nums[i]);
                    s_a2.insert(it, nums[i]);
                    arr2.push_back(nums[i]);
                } else {
                    auto it = lower_bound(s_a1.begin(), s_a1.end(), nums[i]);
                    s_a1.insert(it, nums[i]);
                    arr1.push_back(nums[i]);
                }
            }
        }
        vector<int> ans;
        for (int num : arr1) {
            ans.push_back(num);
        }
        for (int num : arr2) {
            ans.push_back(num);
        }
        return ans;
    }
};