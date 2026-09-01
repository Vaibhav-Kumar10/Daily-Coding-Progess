class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        int n = quality.size();
        vector<pair<double, int>> w_q(n);
        for (int i = 0; i < n; i++) {
            double ratio = (1.0 * wage[i]) / quality[i];
            w_q[i] = {ratio, quality[i]};
        }
        sort(w_q.begin(), w_q.end());

        priority_queue<int> qualities;
        int q_sum = 0;
        for (int i = 0; i < k; i++) {
            int q = w_q[i].second;
            q_sum += q;
            qualities.push(q);
        }

        // Start with k-1 as manager
        double m_r = w_q[k - 1].first;
        double min_pay = q_sum * m_r;
        for (int manager = k; manager < n; manager++) {
            double m_r = w_q[manager].first;
            int cur_q = w_q[manager].second;
            qualities.push(cur_q);
            q_sum += cur_q;

            if (qualities.size() > k) {
                q_sum -= qualities.top();
                qualities.pop();
            }
            double cur_pay = q_sum * m_r;
            min_pay = min(min_pay, cur_pay);
        }
        return min_pay;
    }
    /*
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        int n = quality.size();
        vector<pair<double, int>> w_q(n);
        for (int i = 0; i < n; i++) {
            double ratio = (1.0 * wage[i]) / quality[i];
            w_q[i] = {ratio, quality[i]};
        }
        sort(w_q.begin(), w_q.end());

        double min_pay = DBL_MAX;
        for (int manager = k - 1; manager < n; manager++) {
            priority_queue<double> team;
            for (int worker = 0; worker <= manager; worker++) {
                double worker_min_wage =
                    w_q[worker].second * w_q[manager].first;
                team.push(worker_min_wage);
                if (team.size() > k) {
                    team.pop();
                }
            }
            if (team.size() < k) {
                continue;
            }
            double cur_pay = 0;
            while (!team.empty()) {
                cur_pay += team.top();
                team.pop();
            }
            min_pay = min(min_pay, cur_pay);
        }
        return min_pay;
    }
    */
    /*
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        int n = quality.size();
        vector<double> w_q(n);
        for (int i = 0; i < n; i++) {
            double ratio = (1.0 * wage[i]) / quality[i];
            w_q[i] = ratio;
        }

        double min_pay = DBL_MAX;
        for (int manager = 0; manager < n; manager++) {
            priority_queue<double> team;
            for (int worker = 0; worker < n; worker++) {
                double worker_min_wage = quality[worker] * w_q[manager];
                if (worker_min_wage >= wage[worker]) {
                    team.push(worker_min_wage);
                    if (team.size() > k) {
                        team.pop();
                    }
                }
            }
            if (team.size() < k) {
                continue;
            }
            double cur_pay = 0;
            while (!team.empty()) {
                cur_pay += team.top();
                team.pop();
            }
            min_pay = min(min_pay, cur_pay);
        }
        return min_pay;
    }
    */
};