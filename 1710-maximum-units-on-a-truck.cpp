class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes),
             [&](const auto& a, const auto& b) { return a[1] > b[1]; });
        int box = 0, units = 0, n = boxTypes.size();
        while (box < n && truckSize > 0) {
            int boxes_used = min(boxTypes[box][0], truckSize);
            units += boxes_used * boxTypes[box][1];
            truckSize -= boxes_used;
            box++;
        }
        return units;
    }
};