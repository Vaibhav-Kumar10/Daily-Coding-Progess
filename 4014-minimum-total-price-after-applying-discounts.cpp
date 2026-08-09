class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());
        int n = prices.size(), m = discounts.size();
        int l = 0, r = 0;
        double ans = 0.0;
        while (l < n && r < m) {
            ans += ((prices[l] * 1.0 * (100 - discounts[r])) * 1.0 / 100);
            l++;
            r++;
        }
        while (l < n) {
            ans = ans + prices[l];
            l++;
        }
        return ans;
    }
};