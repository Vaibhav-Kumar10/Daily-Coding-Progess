class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int total = 0, prev = 0;
        for(int t : requests) {
            total += abs(t - prev);
            prev = t;
        }
        return total;
    }
};