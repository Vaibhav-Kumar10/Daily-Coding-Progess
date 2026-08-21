class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int num = 0; num <= n; num++) {
            int one_cnt = 0, num_c = num;
            while (num_c != 0) {
                one_cnt++;
                num_c = num_c & (num_c - 1);
            }
            ans.push_back(one_cnt);
        }
        return ans;
    }
    /*
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int num = 0; num <= n; num++) {
            int one_cnt = 0, num_c = num;
            while(num_c != 0) {
                one_cnt += (num_c & 1);
                num_c >>= 1;
            }
            ans.push_back(one_cnt);
        }
        return ans;
    }
    */
};
