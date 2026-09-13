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
        for (int dr = -(n - 1); dr <= n - 1; dr++) {
            // Horizontal translation
            for (int dc = -(n - 1); dc <= n - 1; dc++) {
                int overlap = 0;
                for (int i = 0; i < n; i++) {
                    int j = i + dr;

                    if (j < 0 || j >= n) {
                        continue;
                    }

                    int shifted = image1_mask[i];

                    if (dc > 0) {
                        shifted <<= dc;
                    } else {
                        shifted >>= -dc;
                    }

                    overlap += __builtin_popcount(shifted & image2_mask[j]);
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};