class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](const auto& a, const auto& b) {
            string a_s = to_string(a);
            string b_s = to_string(b);
            string ab = a_s + b_s;
            string ba = b_s + a_s;
            return ab > ba;
        });
        if (nums[0] == 0) {
            return "0";
        }
        string ans = "";
        for (int num : nums) {
            ans += to_string(num);
        }
        return ans;
    }
};