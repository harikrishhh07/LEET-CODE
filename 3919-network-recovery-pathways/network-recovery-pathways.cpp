class Solution {
public:
    bool check(int n, vector<vector<pair<int,int>>>& g, vector<bool>& online, long long k, int x) {
        vector<int> indegree(n, 0);

        for (int u = 0; u < n; u++) {
            if (u != 0 && u != n - 1 && !online[u]) continue;
            for (auto &[v, w] : g[u]) {
                if (w < x) continue;
                if (v != n - 1 && !online[v]) continue;
                indegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if ((i == 0 || i == n - 1 || online[i]) && indegree[i] == 0)
                q.push(i);
        }

        const long long INF = 4e18;
        vector<long long> dp(n, INF);
        dp[0] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &[v, w] : g[u]) {
                if (w < x) continue;
                if (v != n - 1 && !online[v]) continue;

                if (dp[u] != INF)
                    dp[v] = min(dp[v], dp[u] + (long long)w);

                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        return dp[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> g(n);
        int mx = 0;

        for (auto &e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            mx = max(mx, e[2]);
        }

        int l = 0, r = mx, ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(n, g, online, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};