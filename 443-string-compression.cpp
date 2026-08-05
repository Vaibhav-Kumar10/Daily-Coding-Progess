class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        int n = chars.size(), cnt = 1;
        for (int i = 1; i < n; i++) {
            if (chars[i] == chars[i - 1]) {
                cnt++;
            } else {
                ans.push_back(chars[i - 1]);
                if (cnt != 1) {
                    string cnt_s = to_string(cnt);
                    for (char cnt_c : cnt_s) {
                        ans.push_back(cnt_c);
                    }
                }
                cnt = 1;
            }
        }
        ans.push_back(chars[n - 1]);
        if (cnt != 1) {
            string cnt_s = to_string(cnt);
            for (char cnt_c : cnt_s) {
                ans.push_back(cnt_c);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            chars[i] = ans[i];
        }
        return ans.size();
    }
};