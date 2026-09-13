class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<int> image1_mask(n), image2_mask(n);

        // Convert every row into a bitmask
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                image1_mask[i] |= (img1[i][j] << j);
                image2_mask[i] |= (img2[i][j] << j);
            }
        }

        int ans = 0;

        // Vertical translation
        for (int row_offset = -n + 1; row_offset <= n - 1; row_offset++) {
            // Horizontal translation
            for (int col_offset = -n + 1; col_offset <= n - 1; col_offset++) {
                int overlap = 0;
                for (int row = 0; row < n; row++) {
                    int nr = row + row_offset;
                    if (nr < 0 || nr >= n) {
                        continue;
                    }
                    int shifted = image1_mask[row];

                    if (col_offset > 0) {
                        shifted <<= col_offset;
                    } else {
                        shifted >>= -col_offset;
                    }

                    overlap += __builtin_popcount(shifted & image2_mask[nr]);

                    ans = max(ans, overlap);
                }
            }
        }
        return ans;
    }
};