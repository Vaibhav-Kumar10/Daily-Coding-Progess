class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n, 0);
        size.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findParent(int a) {
        if (a == parent[a]) {
            return a;
        }
        return parent[a] = findParent(parent[a]);
    }
    void union_by_size(int a, int b) {
        int par_a = findParent(a), par_b = findParent(b);
        if (par_a == par_b) {
            return;
        }
        if (size[par_a] >= size[par_b]) {
            parent[par_b] = par_a;
            size[par_a] += size[par_b];
        } else {
            parent[par_a] = par_b;
            size[par_b] += size[par_a];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        vector<string> names(n);
        unordered_map<string, int> email_idx;
        for (int i = 0; i < n; i++) {
            vector<string> cur_acnt = accounts[i];
            names[i] = accounts[i][0];
            for (int j = 1; j < cur_acnt.size(); j++) {
                string email = cur_acnt[j];
                // First time found
                if (email_idx.find(email) == email_idx.end()) {
                    email_idx[email] = i;
                }
                // email already exists => merge into a single component
                else {
                    dsu.union_by_size(i, email_idx[email]);
                }
            }
        }

        vector<vector<string>> merged_email(n);
        // Add mails for each idx node acnt
        for (auto [email, idx] : email_idx) {
            int acnt = dsu.findParent(idx);
            merged_email[acnt].push_back(email);
        }
        
        vector<vector<string>> ans;
        // name, emails
        for (int i = 0; i < n; i++) {
            // no email for acnt => skip
            if (merged_email[i].size() == 0) {
                continue;
            }
            sort(merged_email[i].begin(), merged_email[i].end());
            vector<string> cur;
            // cur.push_back(accounts[i][0]);
            cur.push_back(names[i]);
            for (string email : merged_email[i]) {
                cur.push_back(email);
            }
            ans.push_back(cur);
        }
        return ans;
    }
    /*
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, vector<string>> email_adj;
        unordered_set<string> visited_email;
        // Creating adjacency list for emails.
        for (int i = 0; i < n; i++) {
            vector<string> cur_accnt = accounts[i];
            string email_1 = cur_accnt[1];
            for (int j = 2; j < cur_accnt.size(); j++) {
                string email_2 = cur_accnt[j];
                email_adj[email_1].push_back(email_2);
                email_adj[email_2].push_back(email_1);
            }
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            vector<string> cur_accnt = accounts[i];
            string name = cur_accnt[0];
            string email = cur_accnt[1];
            if (visited_email.find(email) == visited_email.end()) {
                queue<string> q;
                q.push(email);
                vector<string> accnt;
                accnt.push_back(name);
                visited_email.insert(email);
                while (!q.empty()) {
                    string email_1 = q.front();
                    q.pop();
                    accnt.push_back(email_1);
                    for (string email_2 : email_adj[email_1]) {
                        if (visited_email.find(email_2) ==
                            visited_email.end()) {
                            visited_email.insert(email_2);
                            q.push(email_2);
                        }
                    }
                }
                sort(accnt.begin() + 1, accnt.end());
                ans.push_back(accnt);
            }
        }
        return ans;
    }
    */
};