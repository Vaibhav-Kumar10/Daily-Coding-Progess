class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        long long total_tasks = 0;
        int n = tasks.size(), s = shifts.size();
        for (int i = 0; i < n; i++) {
            total_tasks += tasks[i];
        }
        long long cur_rem = total_tasks, rem_cur_task = tasks[0];
        int cur_task = 0;
        vector<int> ans(s, -1);
        for (int i = 0; i < s; i++) {
            if (shifts[i] >= cur_rem) {
                ans[i] = 0;
                cur_rem = total_tasks;
                cur_task = 0;
                rem_cur_task = tasks[0];
            } else {
                long long possible = shifts[i];
                while (possible > 0) {
                    if (possible >= rem_cur_task) {
                        possible -= rem_cur_task;
                        cur_task++;
                        // all done
                        if (cur_task == n) {
                            break;
                        }
                        rem_cur_task = tasks[cur_task];
                    } else {
                        rem_cur_task -= possible;
                        possible = 0;
                    }
                }
                if (cur_task == n) {
                    ans[i] = 0;
                    cur_rem = total_tasks;
                    cur_task = 0;
                    rem_cur_task = tasks[0];
                } else {
                    cur_rem -= shifts[i];
                    ans[i] = n - cur_task;
                }
            }
        }
        return ans;
    }
};