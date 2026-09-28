class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        // store the knowledge as dictionary
        for (auto kp : knowledge) {
            string key = kp[0], value = kp[1];
            dict[key] = value;
        }
        bool key_start = false;
        string ans = "", word = "";
        for (char ch : s) {
            // start the key word
            if (ch == '(') {
                key_start = true;
                word = "";
            }
            // end the key word and get the corresponding value
            else if (ch == ')') {
                key_start = false;
                if (dict.find(word) != dict.end()) {
                    ans += dict[word];
                } else {
                    ans += '?';
                }
            } else {
                if (key_start) {
                    word += ch;
                } else {
                    ans += ch;
                }
            }
        }
        return ans;
    }
};