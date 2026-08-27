class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0, cost_pen = 0;
        while (cost_pen <= total) {
            long long rem_amnt = total - cost_pen;
            long long pencils = rem_amnt / cost2 + 1;
            ways += pencils;
            cost_pen += cost1;
        }
        return ways;
    }
};