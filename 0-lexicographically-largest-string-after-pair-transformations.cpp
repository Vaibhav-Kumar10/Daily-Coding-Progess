class Solution {
public:
    /*
string convert(string s) {
    int n = s.size();
    if (n <= 1) {
        return s;
    }
    string new_s = "";
    new_s += s[0];
    bool changed = false;
    for (int i = 1; i < n; i++) {
        if (s[i] == new_s.back() && s[i] != 'z') {
            changed = true;
            new_s.pop_back();
            new_s += char(s[i] + 1);
        } else {
            new_s += s[i];
        }
    }
    if (changed == false) {
        return new_s;
    }
    return convert(new_s);

    cout << new_s << endl;
}
*/
    vector<string> largestString(vector<int>& nums) {
        /*
        5 => 101
        => position 0 = 1 => => a
        => position 1 = 0 => => ""
        => position 2 = 1 => => c
        ====>>>> ca
        */
        /*
        7 => 111
        => position 0 = 1 => => a
        => position 1 = 1 => => b
        => position 2 = 1 => => c
        ====>>>> cba
        */
        /*
        9 => 1001
        => position 0 = 1 => => a
        => position 1 = 0 => => ""
        => position 2 = 0 => => ""
        => position 3 = 1 => => d
        ====>>>> da
        */

        vector<string> all_str;
        for (int num : nums) {
            string cur_str = "";
            /*
            for (int i = 0; i < num; i++) {
                cur_str += 'a';
            }
            string converted_str = convert(cur_str);
            all_str.push_back(converted_str);
            */
            // no. of z's
            // => 25th bit is 1 => z
            int no_of_z = num / (1 << 25);
            for (int i = 0; i < no_of_z; i++) {
                cur_str += 'z';
            }
            // remaining possible pairs
            int remaining_pairs = num % (1 << 25);
            for (int bit = 24; bit >= 0; bit--) {
                // num = 5 => 000....101
                // 1 << bit = 2^bit
                // bit = 0 => 2^0 = 1 => 1st bit
                // bit = 1 => 2^1 = 2 => 2nd bit
                int num_bit_set = remaining_pairs & (1 << bit);
                if (num_bit_set != 0) {
                    cur_str += char('a' + bit);
                }
            }
            // reverse(begin(cur_str), end(cur_str));
            all_str.push_back(cur_str);
        }
        return all_str;
    }
};