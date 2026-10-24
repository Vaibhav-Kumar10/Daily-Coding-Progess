class Solution {
public:
    int monthDays[13] = {0};
    int findDaysTill(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3));
        // days till prev month + cur days
        return monthDays[month - 1] + day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        vector<int> daysIn = {-1, 31, 28, 31, 30, 31, 30,
                              31, 31, 30, 31, 30, 31};
        monthDays[1] = 31;
        for (int month = 2; month < 13; month++) {
            monthDays[month] = monthDays[month - 1] + daysIn[month];
        }
        // get the days till cur day
        int alice_arrival_day = findDaysTill(arriveAlice);
        int alice_leave_day = findDaysTill(leaveAlice);
        int bob_arrival_day = findDaysTill(arriveBob);
        int bob_leave_day = findDaysTill(leaveBob);

        // only when both are present in Rome
        int min_leave_day = min(alice_leave_day, bob_leave_day);
        int max_arrival_day = max(alice_arrival_day, bob_arrival_day);
        int common_days = min_leave_day - max_arrival_day + 1;
        return common_days < 0 ? 0 : common_days;
    }
};