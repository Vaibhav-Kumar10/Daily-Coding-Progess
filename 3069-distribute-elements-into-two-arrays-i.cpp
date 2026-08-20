class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        int n = nums.size();
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < n; i++) {
            int arr1_last = arr1.back();
            int arr2_last = arr2.back();
            if (arr1_last > arr2_last) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
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