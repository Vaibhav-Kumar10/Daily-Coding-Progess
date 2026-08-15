class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int cntSubarrWithVowelsLTEk(string s, int k) {
        int l = 0, r = 0, n = s.size(), sub_arr_cnt = 0;
        unordered_map<char, int> freq;
        for (r; r < n; r++) {
            // if any consonant found, reset the freq,
            // and start next substring
            if (isVowel(s[r]) == false) {
                l = r + 1;
                freq.clear();
            } else {
                freq[s[r]]++;
                while (l <= r && freq.size() > k) {
                    freq[s[l]]--;
                    if (freq[s[l]] == 0) {
                        freq.erase(s[l]);
                    }
                    l++;
                }
                sub_arr_cnt += (r - l + 1);
            }
        }
        return sub_arr_cnt;
    }
    int countVowelSubstrings(string word) {
        // No. of sub array with at most 5 vowels
        // -
        // No. of sub array with at most 4 vowels
        // =
        // No. of sub array with  5 vowels
        return cntSubarrWithVowelsLTEk(word, 5) -
               cntSubarrWithVowelsLTEk(word, 4);
    }
};