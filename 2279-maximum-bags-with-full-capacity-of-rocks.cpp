class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks,
                    int additionalRocks) {
        int n = capacity.size();
        vector<int> cap_cur(n, 0);
        for (int i = 0; i < n; i++) {
            cap_cur[i] = capacity[i] - rocks[i];
        }
        sort(begin(cap_cur), end(cap_cur));
        int ind = 0, filled = 0;
        while(ind < n && additionalRocks > 0) {
            if (cap_cur[ind] == 0) {
                filled++;
            } else if (cap_cur[ind] <= additionalRocks) {
                additionalRocks -= cap_cur[ind];
                filled++;
            }
            ind++;
        }
        return filled;
    }
};